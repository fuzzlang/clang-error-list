document.addEventListener('DOMContentLoaded', function() {
    console.log('DOM loaded, loading error data...');
    
    // Initialize diagnostic parser (delayed initialization)
    window.diagnosticParser = new DiagnosticParser();
    
    // Load error data first, then initialize parser
    loadErrorData();
    
    // Search functionality
    const searchInput = document.getElementById('searchInput');
    const searchButton = document.getElementById('searchButton');
    
    searchButton.addEventListener('click', function() {
        performSearch(searchInput.value);
    });
    
    searchInput.addEventListener('keypress', function(e) {
        if (e.key === 'Enter') {
            performSearch(searchInput.value);
        }
    });
    
    // Handle anchor links for error codes
    if (window.location.hash) {
        setTimeout(() => {
            const targetElement = document.querySelector(window.location.hash);
            if (targetElement) {
                targetElement.scrollIntoView({ behavior: 'smooth' });
                targetElement.classList.add('highlight');
                setTimeout(() => targetElement.classList.remove('highlight'), 2000);
            }
        }, 1000);
    }
});

// Diagnostic parser class - optimized version
class DiagnosticParser {
    constructor() {
        this.diagnostics = new Map();
        this.fileMapping = new Map();
        this.expandedTemplates = new Map();
        this.initialized = false;
        this.initPromise = null;
    }

    // Delayed initialization method
    initialize() {
        if (this.initPromise) {
            return this.initPromise;
        }
        
        this.initPromise = this._doInitialize();
        return this.initPromise;
    }

    async _doInitialize() {
        if (this.initialized) return Promise.resolve();
        
        const files = [
            'tdfiles/DiagnosticSemaKinds.td',
            'tdfiles/DiagnosticASTKinds.td',
            'tdfiles/DiagnosticCommonKinds.td',
            'tdfiles/DiagnosticDriverKinds.td',
            'tdfiles/DiagnosticFrontendKinds.td',
            'tdfiles/DiagnosticLexKinds.td',
            'tdfiles/DiagnosticParseKinds.td',
            'tdfiles/DiagnosticSerializationKinds.td',
            'tdfiles/DiagnosticAnalysisKinds.td',
            'tdfiles/DiagnosticGroups.td',
            'tdfiles/DiagnosticIndexName.td',
            'tdfiles/DiagnosticCrossTUKinds.td'
        ];

        console.log('Loading all diagnostic files...');

        try {
            // Use Promise.all to load files in parallel
            const fileContents = await Promise.all(
                files.map(fileName => 
                    fetch(fileName)
                        .then(response => {
                            if (!response.ok) {
                                console.error(`Failed to load ${fileName}: ${response.statusText}`);
                                return null;
                            }
                            return response.text().then(content => ({ fileName, content }));
                        })
                        .catch(error => {
                            console.error(`Error loading ${fileName}:`, error);
                            return null;
                        })
                )
            );
            
            // Process file contents in batch
            for (const file of fileContents) {
                if (file) {
                    this.parseContent(file.content, file.fileName);
                }
            }

            // Delay generating expanded templates
            setTimeout(() => {
                this.generateExpandedTemplates();
                console.log(`Successfully loaded ${this.diagnostics.size} diagnostics.`);
                this.initialized = true;
            }, 100);
        } catch (error) {
            console.error('Failed to load .td files:', error);
        }
    }

    parseContent(content, fileName) {
        // Prepare regex to precisely match definition formats in TD files
        const defPattern = /def\s+(\w+)(?:\s*<[^>]*>)?\s*:\s*(Error|Warning|Note|Remark|Extension|ExtWarn)<\s*"([^"]+(?:\s*"[^"]*)*?)"\s*>/g;
        
        // Preprocess content - handle multi-line definitions
        let processedContent = '';
        let inDefinition = false;
        let currentDefinition = '';
        
        const lines = content.split('\n');
        for (let i = 0; i < lines.length; i++) {
            const line = lines[i].trim();
            
            // Start new definition
            if (line.startsWith('def ')) {
                if (currentDefinition) {
                    processedContent += currentDefinition + '\n';
                }
                currentDefinition = line;
                inDefinition = true;
            } 
            // Continue current definition
            else if (inDefinition && line) {
                currentDefinition += ' ' + line;
            }
            
            // Check if definition is complete
            if (inDefinition && line.includes('>;')) {
                processedContent += currentDefinition + '\n';
                currentDefinition = '';
                inDefinition = false;
            }
        }
        
        // Add the last definition (if any)
        if (currentDefinition) {
            processedContent += currentDefinition;
        }
        
        // Use regex to match all definitions
        let match;
        while ((match = defPattern.exec(processedContent)) !== null) {
            const diagId = match[1];
            const diagType = match[2];
            let messageTemplate = match[3].replace(/"\s*"/g, '').replace(/\s+/g, ' ').trim();
            
            // Save diagnostic info to Map
            this.diagnostics.set(diagId, {
                template: messageTemplate,
                type: diagType,
                fileName: fileName
            });
            this.fileMapping.set(diagId, fileName);
            
            // Debug log
            if (diagId.includes('template') && diagId.includes('shadow')) {
                console.log(`Found diagnostic: ${diagId} in ${fileName}`);
            }
        }
    }

    generateExpandedTemplates() {
        // Only generate expansions for templates containing select
        this.diagnostics.forEach((diagInfo, diagId) => {
            const template = diagInfo.template;
            if (template.includes('%select{')) {
                const selectMatches = [...template.matchAll(/%select\{([^}]+)\}(\d+)/g)];
                if (selectMatches.length > 0) {
                    // Limit variant count to avoid combinatorial explosion
                    if (selectMatches.length <= 3) { // Only process cases with at most 3 selects
                        const variants = this.generateVariants(template, selectMatches);
                        this.expandedTemplates.set(diagId, variants);
                    }
                }
            }
        });
    }

    generateVariants(template, selectMatches) {
        // Limit variant count
        const MAX_VARIANTS = 20;
        
        let currentVariants = [template];
        
        for (const match of selectMatches) {
            if (currentVariants.length >= MAX_VARIANTS) break;
            
            const fullMatch = match[0];
            const options = match[1].split('|');
            
            // If too many options, only take the first few
            const limitedOptions = options.length > 5 ? options.slice(0, 5) : options;
            
            const newVariants = [];
            for (const variant of currentVariants) {
                for (const option of limitedOptions) {
                    newVariants.push(variant.replace(fullMatch, option));
                    if (newVariants.length >= MAX_VARIANTS) break;
                }
                if (newVariants.length >= MAX_VARIANTS) break;
            }
            
            currentVariants = newVariants;
        }
        
        // Simplify cleanup process
        return currentVariants.map(variant => 
            variant.replace(/%\d+/g, '')
                  .replace(/%s\d+/g, '')
                  .replace(/%plural\{[^}]+\}\d+/g, '')
                  .replace(/%[a-z]+\d+/g, '')
                  .replace(/\s+/g, ' ').trim()
        );
    }

    // Get diagnostic info by ID
    getDiagnosticInfo(diagId) {
        return this.diagnostics.get(diagId);
    }

    // Optimized search method
    searchDiagnostic(query, threshold = 0.6) {
        if (!this.initialized) {
            console.log('Diagnostic parser not initialized yet');
            return [];
        }
        
        const results = [];
        const queryLower = query.toLowerCase().trim();
        const queryWords = queryLower.split(/\s+/).filter(w => w.length > 0);
        
        console.log(`Searching for: "${queryLower}" (${queryWords.length} words)`);
        
        // First stage: search for exact matches without considering placeholders
        const exactMatches = this.findExactMatches(queryLower, queryWords);
        
        // If we found exact matches, return them
        if (exactMatches.length > 0) {
            console.log(`Found ${exactMatches.length} exact matches`);
            return exactMatches;
        }
        
        // Second stage: consider placeholder-based matches
        console.log('No exact matches found, considering placeholder matches');
        const placeholderMatches = this.findPlaceholderMatches(queryLower, queryWords);
        
        console.log(`Found ${placeholderMatches.length} placeholder-based matches`);
        return placeholderMatches;
    }

    // Find exact matches without considering placeholders
    findExactMatches(query, queryWords) {
        const results = [];
        
        this.diagnostics.forEach((diagInfo, diagId) => {
            const template = diagInfo.template.toLowerCase();
            const id = diagId.toLowerCase();
            
            // Remove placeholders for initial comparison
            const templateWithoutPlaceholders = template.replace(/%\d+/g, '').trim();
            const templateWords = templateWithoutPlaceholders.split(/\s+/).filter(w => w.length > 0);
            
            let matchScore = 0;
            let matched = false;
            
            // Exact ID match
            if (id === query) {
                matchScore = 1.0;
                matched = true;
            }
            // ID contains query
            else if (id.includes(query)) {
                matchScore = 0.9;
                matched = true;
            }
            // Template contains full query (exact template match)
            else if (templateWithoutPlaceholders === query || template === query) {
                matchScore = 0.95;
                matched = true;
            }
            // Template contains query
            else if (templateWithoutPlaceholders.includes(query)) {
                matchScore = 0.8;
                matched = true;
            }
            // Word-by-word match (all query words found in template)
            else if (queryWords.every(word => templateWithoutPlaceholders.includes(word))) {
                // Calculate what percentage of the template text is covered by the query
                const coverage = queryWords.reduce((sum, word) => sum + word.length, 0) / 
                                 templateWithoutPlaceholders.length;
                matchScore = 0.7 + (coverage * 0.2); // 0.7 to 0.9 based on coverage
                matched = true;
            }
            
            if (matched) {
                results.push({
                    diagId,
                    template: diagInfo.template,
                    type: diagInfo.type,
                    fileName: diagInfo.fileName,
                    similarity: matchScore,
                    matchType: "exact"
                });
            }
        });
        
        // Sort by score
        results.sort((a, b) => b.similarity - a.similarity);
        return results;
    }

    // Find matches considering placeholders
    findPlaceholderMatches(query, queryWords) {
        const results = [];
        
        this.diagnostics.forEach((diagInfo, diagId) => {
            const template = diagInfo.template.toLowerCase();
            
            // Skip if doesn't contain placeholders
            if (!template.includes('%')) {
                return;
            }
            
            // Split template into parts by placeholders
            const parts = template.split(/(%\d+)/g).filter(p => p.length > 0);
            
            // Find the fixed parts (non-placeholder parts)
            const fixedParts = parts.filter(p => !p.match(/%\d+/));
            
            // Check if query contains all fixed parts of the template
            const allFixedPartsMatch = fixedParts.every(part => 
                query.includes(part.trim())
            );
            
            if (allFixedPartsMatch) {
                // Calculate how much of the query is covered by fixed parts
                const coverageScore = fixedParts.reduce((sum, part) => 
                    sum + part.trim().length, 0) / query.length;
                
                // Create a mock value by replacing placeholders with sample values
                const mockValue = this.createMockValueFromTemplate(template);
                
                // Calculate similarity between mock value and query
                const similarityScore = this.calculateSimilarity(mockValue, query);
                
                // Combined score - emphasize fixed part coverage
                const matchScore = (coverageScore * 0.7) + (similarityScore * 0.3);
                
                if (matchScore >= 0.4) { // Set a threshold to avoid weak matches
                    results.push({
                        diagId,
                        template: diagInfo.template,
                        type: diagInfo.type,
                        fileName: diagInfo.fileName,
                        similarity: matchScore,
                        matchType: "placeholder"
                    });
                }
            }
        });
        
        // Sort by score
        results.sort((a, b) => b.similarity - a.similarity);
        return results;
    }

    // Create a mock value by replacing placeholders with sample values
    createMockValueFromTemplate(template) {
        return template
            .replace(/%0/g, 'value0')
            .replace(/%1/g, 'value1')
            .replace(/%2/g, 'value2')
            .replace(/%\d+/g, 'value')
            .replace(/%select\{([^}]+)\}\d+/g, (_, options) => options.split('|')[0])
            .replace(/%plural\{([^}]+)\}\d+/g, '$1')
            .replace(/%s\d+/g, 'string')
            .replace(/%[a-z]+\d+/g, 'value');
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
        
        return wordSimilarity;
    }

    // Improved helper method to detect if query is a direct substitution of template
    placeholderTemplateMatchesQuery(template, query) {
        // Split template into fixed parts and placeholders
        const parts = [];
        let lastIndex = 0;
        const placeholderRegex = /%\d+/g;
        let match;
        
        while ((match = placeholderRegex.exec(template)) !== null) {
            // Add text before placeholder
            if (match.index > lastIndex) {
                parts.push({
                    type: 'text',
                    content: template.substring(lastIndex, match.index)
                });
            }
            
            // Add placeholder
            parts.push({
                type: 'placeholder',
                content: match[0]
            });
            
            lastIndex = match.index + match[0].length;
        }
        
        // Add remaining text after last placeholder
        if (lastIndex < template.length) {
            parts.push({
                type: 'text',
                content: template.substring(lastIndex)
            });
        }
        
        // Now try to match the query against these parts
        let currentPosition = 0;
        
        for (const part of parts) {
            if (part.type === 'text') {
                // Fixed text must match exactly
                if (!query.substring(currentPosition).startsWith(part.content)) {
                    return false;
                }
                currentPosition += part.content.length;
            } else {
                // For placeholder, find the next fixed text part
                const nextTextPart = parts.find((p, i) => 
                    parts.indexOf(part) < i && p.type === 'text'
                );
                
                if (!nextTextPart) {
                    // This is the last placeholder, it consumes the rest of the query
                    return currentPosition < query.length;
                }
                
                // Find the next fixed text in the query
                const nextTextIndex = query.indexOf(nextTextPart.content, currentPosition);
                if (nextTextIndex === -1) {
                    return false; // Next fixed text not found
                }
                
                // Make sure placeholder matched something reasonable
                const placeholderValue = query.substring(currentPosition, nextTextIndex);
                if (!this.isReasonablePlaceholderValue(placeholderValue)) {
                    return false;
                }
                
                currentPosition = nextTextIndex;
            }
        }
        
        // We should have consumed the entire query
        return currentPosition === query.length;
    }

    // Helper to determine if a string is a reasonable placeholder value
    isReasonablePlaceholderValue(value) {
        // Placeholder values typically are single tokens without spaces
        // This helps avoid matching arbitrary long strings to placeholders
        if (!value.trim()) return false;
        
        // Too long values are suspicious
        if (value.length > 30) return false;
        
        // Check if the value has reasonable token structure
        // Common placeholder types: type names, variable names, keywords
        return /^[\w<>[\]:&*.,]+$/i.test(value.trim());
    }

    // New helper to check if query is an exact match for a template with placeholders
    isExactPlaceholderMatch(template, query) {
        // First check for the structure (template with placeholders)
        if (!template.match(/%\d+/)) return false;
        
        // Remove placeholder tokens from template
        const templatePattern = template.replace(/%\d+/g, '(.+?)');
        
        // Create regex ensuring exact structure match
        try {
            const regex = new RegExp(`^${templatePattern.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&')}$`, 'i');
            
            // Test if query matches the pattern exactly
            if (regex.test(query)) {
                // Extract the template parts (non-placeholder text)
                const templateParts = template.split(/%\d+/).filter(p => p.length > 0);
                
                // Check that all template parts are in the query
                const allPartsMatch = templateParts.every(part => 
                    query.toLowerCase().includes(part.toLowerCase())
                );
                
                if (allPartsMatch) {
                    // Final check - replace placeholders with what looks like real values
                    // and check if query structure matches
                    const parts = template.split(/(%\d+)/);
                    let testString = '';
                    
                    for (const part of parts) {
                        if (part.match(/%\d+/)) {
                            testString += 'TYPE'; // Substitute placeholder with a typical value
                        } else {
                            testString += part;
                        }
                    }
                    
                    // Check if the structure is similar (same word count, etc.)
                    return Math.abs(testString.split(/\s+/).length - query.split(/\s+/).length) <= 1;
                }
            }
        } catch (e) {
            console.log('Error in exact placeholder match check:', e);
        }
        
        return false;
    }
}

// Global variables for pagination
let currentSearchResults = [];
let currentPage = 1;
const resultsPerPage = 10;

// Perform search function
function performSearch(query) {
    query = query.toLowerCase().trim();
    if (!query) return;
    
    console.log('Searching for:', query);
    
    // Reset pagination
    currentPage = 1;
    
    // Always search in TD files
    searchInTDFiles(query);
}

// Search in TD files
function searchInTDFiles(query) {
    console.log('Searching in TD files');
    const errorListContainer = document.getElementById('error-list-container');
    errorListContainer.innerHTML = '<div class="loading">Searching...</div>';
    
    // Make sure the parser is initialized
    window.diagnosticParser.initialize().then(() => {
        // Get all matching results from diagnostic parser
        const results = window.diagnosticParser.searchDiagnostic(query, 0.4); // Lower threshold to get more results
        
        // Store results globally for pagination
        currentSearchResults = results;
        
        if (results.length > 0) {
            // Display current page of results
            displayPageResults(query);
        } else {
            // Update search results info to show no results
            updateSearchResultsInfo(query, 0);
            errorListContainer.innerHTML = '<div class="no-results">No results found</div>';
            
            // Scroll to error list section
            document.getElementById('error-list').scrollIntoView({ behavior: 'smooth' });
        }
    });
}

// Display current page of results
function displayPageResults(query) {
    const startIndex = (currentPage - 1) * resultsPerPage;
    const endIndex = Math.min(startIndex + resultsPerPage, currentSearchResults.length);
    
    const currentPageResults = currentSearchResults.slice(startIndex, endIndex);
    
    displayTDMatches(currentPageResults, query, {
        currentPage,
        totalPages: Math.ceil(currentSearchResults.length / resultsPerPage),
        totalResults: currentSearchResults.length
    });
}

// Display TD matches with pagination
async function displayTDMatches(results, query, pagination) {
    console.log('Displaying TD matches:', results);
    
    const errorListContainer = document.getElementById('error-list-container');
    errorListContainer.innerHTML = ''; // Clear existing content
    
    const fragment = document.createDocumentFragment();
    
    // Process each result
    const promises = results.map(async diagnostic => {
        // Try to load corresponding JSON file
        const jsonData = await tryLoadJsonForDiagnostic(diagnostic.diagId);
        
        // If JSON doesn't exist, try to load code file
        let codeData = null;
        if (!jsonData) {
            codeData = await tryLoadCodeFileForDiagnostic(diagnostic.diagId);
        }
        
        // Create appropriate card
        const card = jsonData ? 
            createEnhancedErrorCard(jsonData, diagnostic) : 
            (codeData ? 
                createCodeOnlyErrorCard(diagnostic, codeData) : 
                createDiagnosticCard(diagnostic));
        
        return card;
    });
    
    // Wait for all promises to resolve
    const cards = await Promise.all(promises);
    
    // Add cards to fragment
    cards.forEach(card => fragment.appendChild(card));
    
    // Clear container and add cards
    errorListContainer.appendChild(fragment);
    
    // Apply syntax highlighting
    document.querySelectorAll('pre code').forEach(block => {
        hljs.highlightElement(block);
    });
    
    // Add pagination controls if needed
    if (pagination && pagination.totalPages > 1) {
        addPaginationControls(errorListContainer, pagination);
    }
    
    // Update search results info
    updateSearchResultsInfo(query, pagination ? pagination.totalResults : results.length, pagination);
    
    // Scroll to error list section
    document.getElementById('error-list').scrollIntoView({ behavior: 'smooth' });
}

// Add pagination controls to container
function addPaginationControls(container, pagination) {
    // Remove any existing pagination controls
    const existingControls = container.querySelector('.pagination-controls');
    if (existingControls) {
        existingControls.remove();
    }

    // Create new pagination container
    const paginationDiv = document.createElement('div');
    paginationDiv.className = 'pagination-controls';
    
    // Create previous button with SVG icon
    const prevButton = document.createElement('button');
    prevButton.className = 'pagination-btn prev-btn';
    prevButton.disabled = pagination.currentPage <= 1;
    prevButton.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <path d="M15 18l-6-6 6-6"/>
        </svg>
        <span>Previous</span>
    `;
    prevButton.addEventListener('click', () => {
        if (currentPage > 1) {
            currentPage--;
            displayPageResults(document.getElementById('searchInput').value.trim());
        }
    });
    
    // Create next button with SVG icon
    const nextButton = document.createElement('button');
    nextButton.className = 'pagination-btn next-btn';
    nextButton.disabled = pagination.currentPage >= pagination.totalPages;
    nextButton.innerHTML = `
        <span>Next</span>
        <svg xmlns="http://www.w3.org/2000/svg" width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <path d="M9 18l6-6-6-6"/>
        </svg>
    `;
    nextButton.addEventListener('click', () => {
        if (currentPage < pagination.totalPages) {
            currentPage++;
            displayPageResults(document.getElementById('searchInput').value.trim());
        }
    });
    
    // Page info
    const pageInfo = document.createElement('div');
    pageInfo.className = 'page-info';
    pageInfo.innerHTML = `${pagination.currentPage} of ${pagination.totalPages}`;
    
    // Add elements to pagination div
    paginationDiv.appendChild(prevButton);
    paginationDiv.appendChild(pageInfo);
    paginationDiv.appendChild(nextButton);
    
    // Add to container
    container.appendChild(paginationDiv);
}

// Update search results info
function updateSearchResultsInfo(query, foundCount, pagination) {
    const resultsInfo = document.getElementById('search-results-info') || document.createElement('div');
    resultsInfo.id = 'search-results-info';
    resultsInfo.className = 'search-results-info';
    
    if (query !== '') {
        let infoText = `Found ${foundCount} result${foundCount !== 1 ? 's' : ''} for "${query}"`;
        if (pagination && pagination.totalPages > 1) {
            infoText += ` (showing ${(pagination.currentPage - 1) * resultsPerPage + 1}-${Math.min(pagination.currentPage * resultsPerPage, foundCount)} of ${foundCount})`;
        }
        resultsInfo.textContent = infoText;
    } else {
        resultsInfo.textContent = '';
    }
    
    const errorListSection = document.getElementById('error-list');
    const errorListContainer = document.getElementById('error-list-container');
    
    if (errorListSection && errorListContainer && !document.getElementById('search-results-info')) {
        errorListSection.insertBefore(resultsInfo, errorListContainer);
    }
}

// Try to load code file for a diagnostic from success_files folder
async function tryLoadCodeFileForDiagnostic(diagId) {
    // Try different file extensions
    const extensions = ['cpp', 'c', 'cl'];
    
    for (const ext of extensions) {
        const url = `success_files/${diagId}.${ext}`;
        
        try {
            const response = await fetch(url);
            if (response.ok) {
                return {
                    code: await response.text(),
                    extension: ext
                };
            }
        } catch (error) {
            console.log(`Failed to load ${url}: ${error.message}`);
        }
    }
    
    return null; // No code file found
}

// Try to load JSON for a diagnostic
async function tryLoadJsonForDiagnostic(diagId) {
    return fetch(`errors/${diagId}.json`)
        .then(response => {
            if (!response.ok) {
                return null;
            }
            return response.json();
        })
        .catch(() => {
            return null; // Load failed
        });
}

// Create enhanced error card that includes both JSON data and diagnostic template
function createEnhancedErrorCard(errorData, diagnostic) {
    const card = document.createElement('div');
    card.className = 'error-card';
    card.id = errorData.id;
    
    card.innerHTML = `
        <h3 style="color: #4a6bdf;">${errorData.id}</h3>
        <div class="error-description">
            <p>${errorData.description}</p>
            <p><strong>Message Template:</strong> ${diagnostic.template}</p>
            <p><strong>Type:</strong> ${diagnostic.type}</p>
            <p><strong>Source:</strong> ${diagnostic.fileName.split('/').pop()}</p>
        </div>
        <div class="code-example">
            <h4>Example Code:</h4>
            <pre><code class="language-cpp">${errorData.exampleCode}</code></pre>
        </div>
        <div class="error-explanation">
            <h4>Explanation:</h4>
            <p>${errorData.explanation}</p>
        </div>
        <div class="fix-example">
            <h4>Fixed Code:</h4>
            <pre><code class="language-cpp">${errorData.fixedCode}</code></pre>
        </div>
    `;
    
    return card;
}

// Create diagnostic card
function createDiagnosticCard(diagnostic) {
    const card = document.createElement('div');
    card.className = 'error-card';
    card.id = diagnostic.diagId;
    
    // Display the error message template
    let formattedMessage = diagnostic.template || '';
    
    card.innerHTML = `
        <h3 style="color: #4a6bdf;">${diagnostic.diagId}</h3>
        <div class="error-description">
            <p><strong>Message Template:</strong> ${formattedMessage}</p>
            <p><strong>Type:</strong> ${diagnostic.type}</p>
            <p><strong>Source:</strong> ${diagnostic.fileName.split('/').pop()}</p>
        </div>
        <div class="error-explanation">
            <h4>Explanation:</h4>
            <p>This is a Clang diagnostic. For more information, check the Clang documentation.</p>
        </div>
    `;
    
    return card;
}

// Create card for diagnostic with only code example
function createCodeOnlyErrorCard(diagnostic, codeData) {
    const card = document.createElement('div');
    card.className = 'error-card';
    card.id = diagnostic.diagId;
    
    // Helper function to escape HTML special characters
    function escapeHtml(text) {
        return text
            .replace(/&/g, "&amp;")
            .replace(/</g, "&lt;")
            .replace(/>/g, "&gt;")
            .replace(/"/g, "&quot;")
            .replace(/'/g, "&#039;");
    }
    
    card.innerHTML = `
        <h3 style="color: #4a6bdf;">${diagnostic.diagId}</h3>
        <div class="error-description">
            <p><strong>Message Template:</strong> ${escapeHtml(diagnostic.template)}</p>
            <p><strong>Type:</strong> ${diagnostic.type}</p>
            <p><strong>Source:</strong> ${diagnostic.fileName.split('/').pop()}</p>
        </div>
        <div class="code-example">
            <h4>Example Code:</h4>
            <pre><code class="language-${codeData.extension}">${escapeHtml(codeData.code)}</code></pre>
        </div>
        <div class="error-explanation">
            <h4>Explanation:</h4>
            <p>This is an example that demonstrates the error. For more details, check the Clang documentation.</p>
        </div>
    `;
    
    return card;
}

// Load error data function
function loadErrorData() {
    console.log('Attempting to load error data...');
    
    // First initialize the diagnostic parser and wait for it to complete
    window.diagnosticParser.initialize()
        .then(() => {
            console.log('Diagnostic parser initialized, loading error data...');
            return fetch('errors/index.json');
        })
        .then(response => {
            if (!response.ok) {
                throw new Error(`Network response was not ok: ${response.status}`);
            }
            return response.json();
        })
        .then(errorIndex => {
            console.log('Successfully loaded error index');
            
            const errorListContainer = document.getElementById('error-list-container');
            errorListContainer.innerHTML = '';
            
            if (!errorIndex.errors || errorIndex.errors.length === 0) {
                errorListContainer.innerHTML = '<div class="error-message">No errors found in the index.</div>';
                return;
            }
            
            // Batch load error data
            const batchSize = 5;
            const loadBatch = (startIdx) => {
                const endIdx = Math.min(startIdx + batchSize, errorIndex.errors.length);
                const fragment = document.createDocumentFragment();
                
                const promises = [];
                for (let i = startIdx; i < endIdx; i++) {
                    const errorId = errorIndex.errors[i];
                    promises.push(
                        fetch(`errors/${errorId}.json`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Failed to load ${errorId}`);
                                }
                                return response.json();
                            })
                            .then(errorData => {
                                // Get diagnostic info for this error
                                const diagnosticInfo = window.diagnosticParser.getDiagnosticInfo(errorData.id);
                                const errorCard = createErrorCard(errorData, diagnosticInfo);
                                fragment.appendChild(errorCard);
                            })
                            .catch(error => {
                                console.error(`Error loading ${errorId}:`, error);
                            })
                    );
                }
                
                Promise.all(promises).then(() => {
                    errorListContainer.appendChild(fragment);
                    
                    // Apply syntax highlighting
                    document.querySelectorAll('pre code').forEach(block => {
                        hljs.highlightElement(block);
                    });
                    
                    // Load next batch
                    if (endIdx < errorIndex.errors.length) {
                        setTimeout(() => loadBatch(endIdx), 10);
                    } else {
                        // After all batches are loaded, check hash links
                        checkHashLinks();
                    }
                });
            };
            
            // Start batch loading
            loadBatch(0);
        })
        .catch(error => {
            console.error('Error loading error data:', error);
            const errorListContainer = document.getElementById('error-list-container');
            errorListContainer.innerHTML = `<div class="error-message">Error loading data: ${error.message}</div>`;
        });
}

// Create standard error card function
function createErrorCard(errorData, diagnosticInfo) {
    const card = document.createElement('div');
    card.className = 'error-card';
    card.id = errorData.id;
    
    // Helper function to escape HTML special characters
    function escapeHtml(text) {
        return text
            .replace(/&/g, "&amp;")
            .replace(/</g, "&lt;")
            .replace(/>/g, "&gt;")
            .replace(/"/g, "&quot;")
            .replace(/'/g, "&#039;");
    }
    
    // Check if fixed code exists and is not empty
    const hasFixedCode = errorData.fixedCode && errorData.fixedCode.trim().length > 0;
    
    card.innerHTML = `
        <h3 style="color: #4a6bdf;">${errorData.id}</h3>
        <div class="error-description">
            <p>${errorData.description}</p>
            ${diagnosticInfo ? `
            <p><strong>Message Template:</strong> ${escapeHtml(diagnosticInfo.template)}</p>
            <p><strong>Type:</strong> ${diagnosticInfo.type}</p>
            <p><strong>Source:</strong> ${diagnosticInfo.fileName.split('/').pop()}</p>
            ` : ''}
        </div>
        <div class="code-example">
            <h4 style="color: #333;">Example Code:</h4>
            <pre><code class="language-cpp">${escapeHtml(errorData.exampleCode)}</code></pre>
        </div>
        <div class="error-explanation">
            <h4 style="color: #333;">Explanation:</h4>
            <p>${errorData.explanation}</p>
        </div>
        ${hasFixedCode ? `
        <div class="fix-example">
            <h4 style="color: #333;">Fixed Code:</h4>
            <pre><code class="language-cpp">${escapeHtml(errorData.fixedCode)}</code></pre>
        </div>
        ` : ''}
    `;
    
    return card;
}

// Check hash links
function checkHashLinks() {
    if (window.location.hash) {
        const targetElement = document.querySelector(window.location.hash);
        if (targetElement) {
            setTimeout(() => {
                targetElement.scrollIntoView({ behavior: 'smooth' });
                targetElement.classList.add('highlight');
                setTimeout(() => targetElement.classList.remove('highlight'), 2000);
            }, 500);
        }
    }
} 