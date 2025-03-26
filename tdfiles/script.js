class DiagnosticParser {
    constructor() {
        this.diagnostics = new Map();  // Store diagnostic ID and message template
        this.fileMapping = new Map();  // Store diagnostic ID and file name
        this.templatePatterns = new Map(); // Store template patterns for matching
        this.expandedTemplates = new Map(); // Store expanded templates with all possible combinations
    }

    async initialize() {
        const files = [
            'DiagnosticSemaKinds.td',
            'DiagnosticFrontendKinds.td',
            'Diagnostic.td',
            'DiagnosticDocs.td'
        ];

        let loadedFiles = 0;
        const statusDiv = document.getElementById('loadingStatus');
        statusDiv.innerHTML = '<span class="loading">Loading diagnostic files...</span>';

        try {
            for (const fileName of files) {
                try {
                    const response = await fetch(fileName);
                    if (!response.ok) {
                        console.error(`Failed to load ${fileName}: ${response.statusText}`);
                        continue;
                    }
                    const content = await response.text();
                    this.parseContent(content, fileName);
                    loadedFiles++;
                } catch (error) {
                    console.error(`Error loading ${fileName}:`, error);
                }
            }

            // Generate expanded templates for better search
            this.generateExpandedTemplates();

            if (loadedFiles === 0) {
                statusDiv.innerHTML = '<span class="error">Failed to load any diagnostic files. Please make sure you are using a local server.</span>';
            } else {
                statusDiv.innerHTML = `<span class="success">Successfully loaded ${this.diagnostics.size} diagnostics from ${loadedFiles} files.</span>`;
            }
        } catch (error) {
            console.error('Failed to load .td files:', error);
            statusDiv.innerHTML = '<span class="error">Failed to load diagnostic files. Please check console for details.</span>';
        }
    }

    parseContent(content, fileName) {
        // Match multi-line diagnostic definitions
        const pattern = /def\s+(err_\w+)\s*:\s*Error<\s*"([^"]+(?:\s*"[^"]*)*?)"\s*>/gs;
        let match;

        while ((match = pattern.exec(content)) !== null) {
            const diagId = match[1];
            // Process multi-line strings, remove line breaks and extra spaces
            let messageTemplate = match[2].replace(/"\s*"/g, '').replace(/\s+/g, ' ').trim();
            
            // Save original template
            this.diagnostics.set(diagId, messageTemplate);
            this.fileMapping.set(diagId, fileName);
            
            // Create pattern for matching
            this.createTemplatePattern(diagId, messageTemplate);
        }
    }

    generateExpandedTemplates() {
        // Generate all possible combinations of templates with select/plural options
        this.diagnostics.forEach((template, diagId) => {
            // Handle %select{a|b|c}0 format
            const selectMatches = [...template.matchAll(/%select\{([^}]+)\}(\d+)/g)];
            if (selectMatches.length > 0) {
                const variants = this.generateVariants(template, selectMatches);
                this.expandedTemplates.set(diagId, variants);
            }
        });
    }

    generateVariants(template, selectMatches) {
        // Generate all possible combinations of a template with select options
        const variants = [];
        
        // Start with the base template
        let currentVariants = [template];
        
        // Process each %select in order
        for (const match of selectMatches) {
            const fullMatch = match[0];
            const options = match[1].split('|');
            const index = match[2];
            
            // Create new variants by replacing the current %select with each option
            const newVariants = [];
            for (const variant of currentVariants) {
                for (const option of options) {
                    newVariants.push(variant.replace(fullMatch, option));
                }
            }
            
            // Update current variants for next iteration
            currentVariants = newVariants;
        }
        
        // Clean up any remaining format specifiers for better matching
        return currentVariants.map(variant => 
            variant.replace(/%\d+/g, '')
                  .replace(/%s\d+/g, '')
                  .replace(/%plural\{[^}]+\}\d+/g, '')
                  .replace(/%diff\{[^}]+\}\d+,\d+/g, '')
                  .replace(/%human\d+/g, '')
                  .replace(/%ordinal\d+/g, '')
                  .replace(/%objcclass\d+/g, '')
                  .replace(/%objcinstance\d+/g, '')
                  .replace(/%q\d+/g, '')
                  .replace(/%enum_select<[^>]+>\{[^}]+\}\d+/g, '')
                  .replace(/\s+/g, ' ').trim()
        );
    }

    createTemplatePattern(diagId, template) {
        // First, escape regex special characters in the base string
        let patternStr = template.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
        
        // Handle all the different format specifiers
        
        // 1. %select{a|b|c}0 format - creates alternatives
        patternStr = patternStr.replace(/%select\{([^}]+)\}\d+/g, (match, options) => {
            const parts = options.split('|').map(part => part.replace(/[.*+?^${}()|[\]\\]/g, '\\$&'));
            return `(${parts.join('|')})`;
        });
        
        // 2. %plural{expr:form|expr:form}0 format
        patternStr = patternStr.replace(/%plural\{([^}]+)\}\d+/g, (match, options) => {
            const forms = options.split('|').map(form => {
                // Just take the form part after the expression
                const formPart = form.split(':')[1] || form;
                return formPart.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
            });
            return `(${forms.join('|')})`;
        });
        
        // 3. %diff{from $ to $|from argument type to parameter type}1,2 format
        patternStr = patternStr.replace(/%diff\{([^}]+)\}\d+,\d+/g, (match, options) => {
            const parts = options.split('|')[0].split('$');
            if (parts.length >= 2) {
                const beforeText = parts[0].replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
                const afterText = parts[1].replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
                return `${beforeText}(.+?)${afterText}`;
            }
            return '(.+?)';
        });
        
        // 4. %0, %1, etc. placeholders
        patternStr = patternStr.replace(/%\d+/g, '(.+?)');
        
        // 5. %s0 format (singular/plural 's')
        patternStr = patternStr.replace(/%s\d+/g, '(?:s)?');
        
        // 6. %human0 format (human-readable size)
        patternStr = patternStr.replace(/%human\d+/g, '([\\d.]+(?:k|M|G|T)?)');
        
        // 7. %ordinal0 format (1st, 2nd, 3rd, etc.)
        patternStr = patternStr.replace(/%ordinal\d+/g, '(\\d+(?:st|nd|rd|th))');
        
        // 8. %objcclass0 and %objcinstance0 formats
        patternStr = patternStr.replace(/%objcclass\d+/g, '\\+[\\w:]+');
        patternStr = patternStr.replace(/%objcinstance\d+/g, '\\-[\\w:]+');
        
        // 9. %q0 format (fully qualified name)
        patternStr = patternStr.replace(/%q\d+/g, '([\\w:]+)');
        
        // 10. %enum_select format (similar to select)
        patternStr = patternStr.replace(/%enum_select<[^>]+>\{([^}]+)\}\d+/g, (match, options) => {
            const parts = options.split('|').map(part => {
                // Extract the text part from %Type{text} format
                const textMatch = part.match(/%\w+\{([^}]+)\}/);
                return textMatch ? textMatch[1].replace(/[.*+?^${}()|[\]\\]/g, '\\$&') : 
                                  part.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
            });
            return `(${parts.join('|')})`;
        });
        
        // Create regex with word boundaries and case insensitivity
        try {
            // Make the pattern more flexible for search by allowing any characters between parts
            patternStr = patternStr.replace(/\\\(/g, '\\s*\\(\\s*')
                                  .replace(/\\\)/g, '\\s*\\)\\s*')
                                  .replace(/\s+/g, '\\s+');
            
            const pattern = new RegExp(patternStr, 'i');
            this.templatePatterns.set(diagId, pattern);
        } catch (e) {
            console.error(`Failed to create pattern for ${diagId}: ${e.message}`);
        }
    }

    searchDiagnostic(query, threshold = 0.6) {
        const results = [];
        const queryLower = query.toLowerCase();
        
        // First, search in expanded templates (all possible combinations of select options)
        this.expandedTemplates.forEach((variants, diagId) => {
            for (const variant of variants) {
                if (variant.toLowerCase().includes(queryLower)) {
                    results.push({
                        diagId,
                        template: this.diagnostics.get(diagId),
                        similarity: 1.0, // Exact match in expanded template
                        fileName: this.fileMapping.get(diagId) || "Unknown file",
                        matchType: "expanded",
                        matchedVariant: variant
                    });
                    break; // Found a match for this diagnostic, no need to check other variants
                }
            }
        });
        
        // If we found expanded matches, return them
        if (results.length > 0) {
            results.sort((a, b) => b.similarity - a.similarity);
            return results;
        }
        
        // Next, try pattern matching for templates with format specifiers
        this.diagnostics.forEach((template, diagId) => {
            if (template.includes('%select') || 
                template.includes('%plural') || 
                template.includes('%diff') ||
                template.includes('%s') ||
                template.includes('%human') ||
                template.includes('%ordinal')) {
                
                const pattern = this.templatePatterns.get(diagId);
                if (pattern && pattern.test(query)) {
                    results.push({
                        diagId,
                        template,
                        similarity: 0.95, // Exact pattern match
                        fileName: this.fileMapping.get(diagId) || "Unknown file",
                        matchType: "exact"
                    });
                    return;
                }
            }
        });
        
        // If we found exact pattern matches, return them
        if (results.length > 0) {
            results.sort((a, b) => b.similarity - a.similarity);
            return results;
        }
        
        // Next, try keyword matching
        this.diagnostics.forEach((template, diagId) => {
            const templateLower = template.toLowerCase();
            
            // Extract the text parts from the template (ignoring format specifiers)
            const templateText = templateLower.replace(/%[a-z_]+\{[^}]+\}\d+(?:,\d+)?/g, ' ')
                                            .replace(/%\w+\d+(?:,\d+)?/g, ' ')
                                            .replace(/\s+/g, ' ').trim();
            
            // Check if the query is a substring of the template text
            if (templateText.includes(queryLower)) {
                results.push({
                    diagId,
                    template,
                    similarity: 0.9, // High similarity for substring matches
                    fileName: this.fileMapping.get(diagId) || "Unknown file",
                    matchType: "keyword"
                });
                return;
            }
            
            // Check if any significant word in the query is in the template
            const queryWords = queryLower.split(/\s+/).filter(word => word.length > 3);
            let wordMatches = 0;
            for (const word of queryWords) {
                if (templateText.includes(word)) {
                    wordMatches++;
                }
            }
            
            if (wordMatches > 0) {
                const wordMatchRatio = wordMatches / queryWords.length;
                results.push({
                    diagId,
                    template,
                    similarity: 0.7 + (wordMatchRatio * 0.2), // Adjust similarity based on word match ratio
                    fileName: this.fileMapping.get(diagId) || "Unknown file",
                    matchType: "keyword",
                    wordMatches: wordMatches
                });
                return;
            }
            
            // Fallback to similarity calculation
            const similarity = this.calculateSimilarity(queryLower, templateText);
            if (similarity > threshold) {
                results.push({
                    diagId,
                    template,
                    similarity,
                    fileName: this.fileMapping.get(diagId) || "Unknown file",
                    matchType: "fuzzy"
                });
            }
        });

        // Sort by similarity
        results.sort((a, b) => b.similarity - a.similarity);
        return results;
    }

    calculateSimilarity(s1, s2) {
        if (s1.length < 2 || s2.length < 2) return 0;

        // Split strings into words
        const words1 = s1.split(/\s+/);
        const words2 = s2.split(/\s+/);
        
        // Count common words
        const commonWords = words1.filter(word => 
            words2.some(w => w.includes(word) || word.includes(w))
        );
        
        // Calculate word-level similarity
        const wordSimilarity = (2.0 * commonWords.length) / (words1.length + words2.length);
        
        // Calculate character-level similarity (bigrams)
        let matches = 0;
        let i = 0;
        let j = 0;

        while (i < s1.length - 1) {
            const gram1 = s1.slice(i, i + 2);
            j = 0;
            while (j < s2.length - 1) {
                const gram2 = s2.slice(j, j + 2);
                if (gram1 === gram2) {
                    matches++;
                }
                j++;
            }
            i++;
        }
        
        const charSimilarity = (2.0 * matches) / (s1.length + s2.length - 2);
        
        // Combine similarities with higher weight for word-level
        return wordSimilarity * 0.7 + charSimilarity * 0.3;
    }
}

// Initialize
document.addEventListener('DOMContentLoaded', async () => {
    const parser = new DiagnosticParser();
    const searchInput = document.getElementById('searchInput');
    const searchBtn = document.getElementById('searchBtn');
    const resultDiv = document.getElementById('result');

    // Initialize and load files
    await parser.initialize();

    const performSearch = () => {
        const query = searchInput.value.trim();
        if (!query) {
            resultDiv.innerHTML = '<p>Please enter a search query.</p>';
            return;
        }

        const results = parser.searchDiagnostic(query);
        
        if (results.length === 0) {
            resultDiv.innerHTML = '<p>No matching diagnostics found. Try different keywords.</p>';
            return;
        }

        const resultsHtml = results.slice(0, 10).map((result, index) => {
            let matchInfo = '';
            if (result.matchType === "expanded") {
                matchInfo = `<span class="exact-match">(Expanded Match: "${result.matchedVariant}")</span>`;
            } else if (result.matchType === "exact") {
                matchInfo = '<span class="exact-match">(Exact Match)</span>';
            }
            
            return `
                <div class="result-item">
                    <div><strong>${index + 1}. ${result.diagId}</strong> ${matchInfo}</div>
                    <div class="similarity">Similarity: ${result.similarity.toFixed(2)}</div>
                    <div>Template: "${result.template}"</div>
                    <div class="file-name">File: ${result.fileName}</div>
                </div>
            `;
        }).join('');

        resultDiv.innerHTML = `<p>Found ${results.length} potential matches:</p>${resultsHtml}`;
    };

    searchBtn.addEventListener('click', performSearch);
    searchInput.addEventListener('keypress', (e) => {
        if (e.key === 'Enter') {
            performSearch();
        }
    });
}); 