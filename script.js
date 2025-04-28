document.addEventListener('DOMContentLoaded', function() {
    console.log('DOM loaded, loading error data...');
    
    // Initialize diagnostic parser (delayed initialization)
    window.diagnosticParser = new DiagnosticParser();
    
    // Initialize the parser immediately
    window.diagnosticParser.initialize()
        .then(() => {
            console.log('Diagnostic parser initialized during page load');
            // Load error data after parser is initialized
            loadErrorData();
        })
        .catch(error => {
            console.error('Error initializing diagnostic parser during page load:', error);
            // Try to load error data anyway
            loadErrorData();
        });
    
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
            './tdfiles/DiagnosticSemaKinds.td',
            './tdfiles/DiagnosticASTKinds.td',
            './tdfiles/DiagnosticCommonKinds.td',
            './tdfiles/DiagnosticDriverKinds.td',
            './tdfiles/DiagnosticFrontendKinds.td',
            './tdfiles/DiagnosticLexKinds.td',
            './tdfiles/DiagnosticParseKinds.td',
            './tdfiles/DiagnosticSerializationKinds.td',
            './tdfiles/DiagnosticGroups.td',
            './tdfiles/DiagnosticCrossTUKinds.td',
            './tdfiles/DiagnosticRefactoringKinds.td',
            './tdfiles/DiagnosticInstallAPIKinds.td',
            './tdfiles/DiagnosticCommentKinds.td'
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

            // Generate expanded templates immediately instead of using setTimeout
            this.generateExpandedTemplates();
            console.log(`Successfully loaded ${this.diagnostics.size} diagnostics.`);
            this.initialized = true;
            
            // Check if we have diagnostics
            if (this.diagnostics.size === 0) {
                console.error('No diagnostics loaded from TD files');
                throw new Error('No diagnostics loaded');
            }
            
            return Promise.resolve();
        } catch (error) {
            console.error('Failed to load .td files:', error);
            return Promise.reject(error);
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

    // Get all diagnostics as an array
    getAllDiagnostics() {
        const diagArray = [];
        this.diagnostics.forEach((diagInfo, diagId) => {
            diagArray.push({
                diagId: diagId,
                ...diagInfo
            });
        });
        return diagArray;
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

// Global variables for TD files pagination
let tdCurrentPage = 1;
const tdItemsPerPage = 10;
let tdTotalPages = 1;
let filteredTDDiagnostics = [];

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
async function displayPageResults(query) {
    const startIndex = (currentPage - 1) * resultsPerPage;
    const endIndex = Math.min(startIndex + resultsPerPage, currentSearchResults.length);
    
    const currentPageResults = currentSearchResults.slice(startIndex, endIndex);
    
    await displayTDMatches(currentPageResults, query, {
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
    prevButton.addEventListener('click', async () => {
        if (currentPage > 1) {
            currentPage--;
            await displayPageResults(document.getElementById('searchInput').value.trim());
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
    nextButton.addEventListener('click', async () => {
        if (currentPage < pagination.totalPages) {
            currentPage++;
            await displayPageResults(document.getElementById('searchInput').value.trim());
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
    
    const descriptionElement = document.getElementById('error-list-description');
    
    if (query !== '') {
        // Show search results info
        resultsInfo.style.display = 'block';
        
        // Update description text for search context
        if (descriptionElement) {
            if (foundCount > 0) {
                descriptionElement.textContent = 'Search results for your query:';
            } else {
                descriptionElement.textContent = 'No results found for your search:';
            }
        }
        
        let infoText = `Found ${foundCount} result${foundCount !== 1 ? 's' : ''} for "${query}"`;
        if (pagination && pagination.totalPages > 1) {
            infoText += ` (showing ${(pagination.currentPage - 1) * resultsPerPage + 1}-${Math.min(pagination.currentPage * resultsPerPage, foundCount)} of ${foundCount})`;
        }
        resultsInfo.textContent = infoText;
    } else {
        // Hide search results info
        resultsInfo.style.display = 'none';
        resultsInfo.textContent = '';
        
        // Reset description to default
        if (descriptionElement) {
            descriptionElement.textContent = 'Below is a comprehensive list of Clang error codes with explanations and examples:';
        }
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
    
    // 添加超时控制
    const timeout = 2000; // 2秒超时
    
    for (const ext of extensions) {
        const url = `./success_files/${diagId}.${ext}`;
        
        try {
            // 创建一个带超时的Promise
            const fetchPromise = fetch(url);
            const timeoutPromise = new Promise((_, reject) => 
                setTimeout(() => reject(new Error('Request timeout')), timeout)
            );
            
            // 使用Promise.race选择先完成的Promise
            const response = await Promise.race([fetchPromise, timeoutPromise]);
            
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
    // 添加超时控制
    const timeout = 2000; // 2秒超时
    
    try {
        // 创建一个带超时的Promise
        const fetchPromise = fetch(`./errors/${diagId}.json`);
        const timeoutPromise = new Promise((_, reject) => 
            setTimeout(() => reject(new Error('Request timeout')), timeout)
        );
        
        // 使用Promise.race选择先完成的Promise
        const response = await Promise.race([fetchPromise, timeoutPromise]);
        
        if (!response.ok) {
            return null;
        }
        return response.json();
    } catch (error) {
        console.log(`Failed to load JSON for ${diagId}: ${error.message}`);
        return null; // Load failed
    }
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
            <p><strong>Message Template:</strong> <span class="code-msg">${diagnostic.template}</span></p>
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
    
    // Helper function to escape HTML special characters
    function escapeHtml(text) {
        if (!text) return '';
        return text
            .replace(/&/g, "&amp;")
            .replace(/</g, "&lt;")
            .replace(/>/g, "&gt;")
            .replace(/"/g, "&quot;")
            .replace(/'/g, "&#039;");
    }
    
    // Get friendly type label with color
    const getTypeLabel = (type) => {
        switch(type) {
            case 'Error': return '<span style="color:#e53935">Error</span>';
            case 'Warning': return '<span style="color:#ff9800">Warning</span>';
            case 'Note': return '<span style="color:#43a047">Note</span>';
            case 'Remark': return '<span style="color:#3949ab">Remark</span>';
            case 'Extension': return '<span style="color:#8e24aa">Extension</span>';
            case 'ExtWarn': return '<span style="color:#ef6c00">Extension Warning</span>';
            default: return type || 'Unknown';
        }
    };
    
    // Extract diagnostic source from filename
    const getSourceLabel = (fileName) => {
        if (!fileName) return 'Unknown';
        
        const basename = fileName.split('/').pop();
        // Extract category from diagnostic filename
        const match = basename.match(/Diagnostic(.*?)Kinds\.td/);
        if (match && match[1]) {
            return match[1] || basename;
        }
        return basename;
    };
    
    // Display the error message template
    let formattedMessage = diagnostic.template || '';
    
    card.innerHTML = `
        <h3 style="color: #4a6bdf;">${diagnostic.diagId}</h3>
        <div class="error-description">
            <p><strong>Message Template:</strong> <span class="code-msg">${escapeHtml(formattedMessage)}</span></p>
            <p><strong>Type:</strong> ${getTypeLabel(diagnostic.type)}</p>
            <p><strong>Source:</strong> ${getSourceLabel(diagnostic.fileName)}</p>
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
            <p><strong>Message Template:</strong> <span class="code-msg">${escapeHtml(diagnostic.template)}</span></p>
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
    
    // Clear content
    const errorListContainer = document.getElementById('error-list-container');
    errorListContainer.innerHTML = '<div class="loading">Loading error data...</div>';
    
    // Initialize diagnostic parser first
    window.diagnosticParser.initialize()
        .then(() => {
            console.log('Diagnostic parser initialized successfully');
            
            if (!window.diagnosticParser.initialized) {
                console.error('Diagnostic parser initialize() completed but initialized flag is false');
                throw new Error('Diagnostic parser not fully initialized');
            }
            
            // Clear loading indicator
            const loadingIndicator = errorListContainer.querySelector('.loading');
            if (loadingIndicator) {
                loadingIndicator.remove();
            }
            
            // Clear all content from container
            errorListContainer.innerHTML = '';
            
            // 只创建一个诊断容器，避免重复
            const diagnosticsContainer = document.createElement('div');
            diagnosticsContainer.id = 'diagnostics-container';
            errorListContainer.appendChild(diagnosticsContainer);
            
            // Sequential loading process
            const loadProcess = async () => {
                try {
                    // 直接加载TD files诊断，跳过error examples
                    await loadTDFilesErrors(diagnosticsContainer);
                    
                    console.log('All content loaded');
                } catch (error) {
                    console.error('Error during load process:', error);
                }
            };
            
            // Start loading process
            loadProcess();
        })
        .catch(error => {
            console.error('Error initializing diagnostic parser:', error);
            errorListContainer.innerHTML = `<div class="error-message">Error initializing diagnostic parser: ${error.message}</div>`;
        });
}

// Function to load errors from errors/index.json
function loadErrorsFromJson(errorIndex, container) {
    // Load each error from the index
    const promises = errorIndex.errors.map(errorId => {
        return fetch(`./errors/${errorId}.json`)
            .then(response => {
                if (!response.ok) {
                    console.error(`Failed to load ${errorId}`);
                    return null;
                }
                return response.json();
            })
            .then(errorData => {
                if (!errorData) return null;
                
                // Get diagnostic info for this error
                const diagnosticInfo = window.diagnosticParser.getDiagnosticInfo(errorData.id);
                const errorCard = createErrorCard(errorData, diagnosticInfo);
                return errorCard;
            })
            .catch(error => {
                console.error(`Error loading ${errorId}:`, error);
                return null;
            });
    });
    
    // Return a promise that resolves when all cards are loaded and added to the container
    return Promise.all(promises)
        .then(cards => {
            // Filter out null results
            const validCards = cards.filter(card => card !== null);
            
            if (validCards.length === 0) {
                const noErrors = document.createElement('div');
                noErrors.className = 'no-results';
                noErrors.textContent = 'No error examples could be loaded.';
                container.appendChild(noErrors);
            } else {
                // Add all cards to the container directly
                validCards.forEach(card => {
                    container.appendChild(card);
                });
            }
            
            // Apply syntax highlighting
            document.querySelectorAll('pre code').forEach(block => {
                hljs.highlightElement(block);
            });
            
            console.log(`Loaded ${validCards.length} error examples`);
            return validCards.length;
        });
}

// Function to load diagnostics from TD files
function loadTDFilesErrors(container) {
    return new Promise((resolve, reject) => {
        if (!window.diagnosticParser) {
            const error = new Error('Diagnostic parser not created');
            console.error(error.message);
            
            // Create error message in UI
            const errorDiv = document.createElement('div');
            errorDiv.className = 'error-message';
            errorDiv.textContent = 'Error: Diagnostic parser not available';
            container.appendChild(errorDiv);
            
            reject(error);
            return;
        }
        
        // 检查是否已经存在诊断区域
        if (container.querySelector('#diagnostics-section')) {
            console.log('诊断区域已存在，直接使用现有容器');
            const existingSection = container.querySelector('#diagnostics-section');
            
            if (!window.diagnosticParser.initialized) {
                console.log('诊断解析器未初始化，现在初始化');
                window.diagnosticParser.initialize()
                    .then(() => {
                        loadTDFilesAfterInit(existingSection, resolve, reject);
                    })
                    .catch(error => {
                        console.error('初始化诊断解析器失败:', error);
                        reject(error);
                    });
            } else {
                loadTDFilesAfterInit(existingSection, resolve, reject);
            }
            return;
        }
        
        // 如果不存在，创建新的诊断区域
        const diagnosticsSection = document.createElement('div');
        diagnosticsSection.id = 'diagnostics-section';
        container.appendChild(diagnosticsSection);
        
        if (!window.diagnosticParser.initialized) {
            console.log('Diagnostic parser not initialized, initializing now...');
            
            // Try to initialize the parser
            window.diagnosticParser.initialize()
                .then(() => {
                    console.log('Diagnostic parser successfully initialized');
                    // Continue with loading TD files
                    loadTDFilesAfterInit(diagnosticsSection, resolve, reject);
                })
                .catch(error => {
                    console.error('Failed to initialize diagnostic parser:', error);
                    
                    // Create error message in UI
                    const errorDiv = document.createElement('div');
                    errorDiv.className = 'error-message';
                    errorDiv.textContent = `Error: Failed to initialize diagnostic parser: ${error.message}`;
                    diagnosticsSection.appendChild(errorDiv);
                    
                    reject(error);
                });
        } else {
            // Parser is already initialized
            loadTDFilesAfterInit(diagnosticsSection, resolve, reject);
        }
    });
}

// Helper function to load TD files after parser is initialized
async function loadTDFilesAfterInit(container, resolve, reject) {
    try {
        console.log('Loading errors from TD files...');
        
        // Clear content but preserve error messages
        let errorMessage = container.querySelector('.error-message');
        
        container.innerHTML = '';
        
        if (errorMessage) {
            container.appendChild(errorMessage);
        }
        
        // Create section title
        const sectionTitle = document.createElement('h2');
        sectionTitle.textContent = 'Clang Diagnostics';
        sectionTitle.className = 'section-title';
        sectionTitle.id = 'td-diagnostics';
        container.appendChild(sectionTitle);
        
        // Get all diagnostics from TD files
        const diagnostics = window.diagnosticParser.getAllDiagnostics();
        console.log(`Found ${diagnostics.length} diagnostics from TD files`);
        
        if (diagnostics.length === 0) {
            const noResultsDiv = document.createElement('div');
            noResultsDiv.className = 'no-results';
            noResultsDiv.textContent = 'No diagnostics found in TD files.';
            container.appendChild(noResultsDiv);
            
            if (resolve) resolve();
            return;
        }
        
        // Sort diagnostics: err_ first, followed by warn_, then others
        // First sort without checking for examples and JSON (to avoid excessive HTTP requests)
        filteredTDDiagnostics = diagnostics.map(diag => {
            return {
                ...diag,
                hasCodeExample: false, // 初始设为false，稍后只为显示的项检查
                hasJson: false
            };
        });
        
        // Sort diagnostics based on prefix first
        filteredTDDiagnostics.sort((a, b) => {
            // Sort by prefix
            if (a.diagId.startsWith('err_') && !b.diagId.startsWith('err_')) return -1;
            if (!a.diagId.startsWith('err_') && b.diagId.startsWith('err_')) return 1;
            
            if (a.diagId.startsWith('warn_') && !b.diagId.startsWith('warn_')) return -1;
            if (!a.diagId.startsWith('warn_') && b.diagId.startsWith('warn_')) return 1;
            
            // Finally, sort alphabetically
            return a.diagId.localeCompare(b.diagId);
        });
        
        // Reset pagination
        tdCurrentPage = 1;
        tdTotalPages = Math.ceil(filteredTDDiagnostics.length / tdItemsPerPage);
        
        // Display first page
        await displayTDPageAfterTitle(sectionTitle, container);
        
        if (resolve) resolve();
    } catch (error) {
        console.error('Error loading TD files:', error);
        
        // Display error message
        const errorDiv = document.createElement('div');
        errorDiv.className = 'error-message';
        errorDiv.textContent = `Error loading TD files: ${error.message}`;
        container.appendChild(errorDiv);
        
        if (reject) reject(error);
    }
}

// Function to display a page of TD diagnostics
async function displayTDPage(container) {
    console.log(`Displaying TD page ${tdCurrentPage} of ${tdTotalPages}`);
    
    // Find the section title
    const sectionTitle = container.querySelector('.section-title');
    if (!sectionTitle) {
        console.error('Could not find TD section title, creating one');
        // If no title found, create one
        const newSectionTitle = document.createElement('h3');
        newSectionTitle.className = 'section-title';
        newSectionTitle.textContent = 'Clang Diagnostics';
        container.appendChild(newSectionTitle);
        
        // Use the new created title
        await displayTDPageAfterTitle(newSectionTitle, container);
        
        // 滚动到新创建的标题
        newSectionTitle.scrollIntoView({ behavior: 'smooth' });
    } else {
        await displayTDPageAfterTitle(sectionTitle, container);
        
        // 页面内容加载完成后，滚动到标题位置
        sectionTitle.scrollIntoView({ behavior: 'smooth' });
    }
}

// Display TD page content after the title
async function displayTDPageAfterTitle(sectionTitle, container) {
    // 清除所有存在的元素
    // Remove existing TD cards
    const tdCards = container.querySelectorAll('.error-card-td');
    tdCards.forEach(card => card.remove());
    
    // 移除所有现有的分页相关元素
    container.querySelectorAll('.pagination-wrapper').forEach(el => el.remove());
    container.querySelectorAll('.pagination-controls').forEach(el => el.remove());
    container.querySelectorAll('.search-results-info').forEach(el => el.remove());
    
    // Calculate start and end indices for current page
    const startIndex = (tdCurrentPage - 1) * tdItemsPerPage;
    const endIndex = Math.min(startIndex + tdItemsPerPage, filteredTDDiagnostics.length);
    
    // Get diagnostics for current page
    const pageDiagnostics = filteredTDDiagnostics.slice(startIndex, endIndex);
    
    // Create a container for cards
    const cardsContainer = document.createElement('div');
    cardsContainer.className = 'td-cards-container';
    
    // Loading indicator
    const loadingIndicator = document.createElement('div');
    loadingIndicator.className = 'loading';
    loadingIndicator.textContent = 'Loading example code...';
    cardsContainer.appendChild(loadingIndicator);
    
    // 一个唯一ID的容器，确保内容不会重复
    cardsContainer.id = 'td-cards-' + Date.now();
    
    // Insert cards container after section title
    sectionTitle.after(cardsContainer);
    
    // Process each diagnostic with example code (similar to search function)
    const cardPromises = pageDiagnostics.map(async diagnostic => {
        // 先标记当前项是否有JSON或代码示例
        // First try to load JSON file
        let jsonData = null;
        try {
            jsonData = await tryLoadJsonForDiagnostic(diagnostic.diagId);
            if (jsonData) {
                diagnostic.hasJson = true;
            }
        } catch (error) {
            console.log(`Error loading JSON for ${diagnostic.diagId}: ${error.message}`);
        }
        
        // If JSON doesn't exist, try to load code file
        let codeData = null;
        if (!jsonData) {
            try {
                codeData = await tryLoadCodeFileForDiagnostic(diagnostic.diagId);
                if (codeData) {
                    diagnostic.hasCodeExample = true;
                }
            } catch (error) {
                console.log(`Error loading code for ${diagnostic.diagId}: ${error.message}`);
            }
        }
        
        // Create appropriate card based on available data
        let card;
        try {
            if (jsonData) {
                card = createEnhancedErrorCard(jsonData, diagnostic);
            } else if (codeData) {
                card = createCodeOnlyErrorCard(diagnostic, codeData);
            } else {
                card = createDiagnosticCard(diagnostic);
            }
            
            card.classList.add('error-card-td');
            return card;
        } catch (error) {
            console.error(`Error creating card for ${diagnostic.diagId}: ${error.message}`);
            // 返回一个简单的错误卡片作为后备
            const errorCard = document.createElement('div');
            errorCard.className = 'error-card error-card-td';
            errorCard.innerHTML = `<h3>${diagnostic.diagId}</h3><p>Error loading details: ${error.message}</p>`;
            return errorCard;
        }
    });
    
    // Wait for all cards to be created
    const cards = await Promise.all(cardPromises);
    
    // Remove loading indicator
    loadingIndicator.remove();
    
    // Add cards to container
    cards.forEach(card => cardsContainer.appendChild(card));
    
    // Apply syntax highlighting
    document.querySelectorAll('pre code').forEach(block => {
        hljs.highlightElement(block);
    });
    
    // 添加底部分页控件 (如果有多页)
    if (tdTotalPages > 1) {
        // 使用帮助函数创建底部分页控件
        createPaginationUI(container, sectionTitle, 'bottom');
    }
    
    // Check hash links
    checkHashLinks();
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
            <p><strong>Message Template:</strong> <span class="code-msg">${escapeHtml(diagnosticInfo.template)}</span></p>
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

// Search function
async function search() {
    const query = document.getElementById('searchInput').value.toLowerCase();
    const resultsContainer = document.getElementById('searchResults');
    
    // Clear previous results
    resultsContainer.innerHTML = '';
    
    if (!query) {
        return;
    }
    
    const loadingIndicator = document.createElement('div');
    loadingIndicator.className = 'loading';
    loadingIndicator.textContent = 'Searching...';
    resultsContainer.appendChild(loadingIndicator);
    
    try {
        let matches = [];
        
        // Check if we need to wait for parser initialization
        if (!window.diagnosticParser || !window.diagnosticParser.isInitialized) {
            await waitForParserInitialization();
        }
        
        // Search in error examples
        if (window.errorExamples) {
            const exampleMatches = window.errorExamples.filter(error => {
                return error.id.toLowerCase().includes(query) || 
                       error.message.toLowerCase().includes(query) ||
                       (error.description && error.description.toLowerCase().includes(query));
            });
            matches = [...matches, ...exampleMatches];
        }
        
        // Search in additional diagnostics
        if (window.diagnosticParser && window.diagnosticParser.diagnostics) {
            const diagnosticMatches = Array.from(window.diagnosticParser.diagnostics.entries())
                .filter(([diagId, diagInfo]) => {
                    return diagId.toLowerCase().includes(query) || 
                           diagInfo.text.toLowerCase().includes(query) ||
                           (diagInfo.description && diagInfo.description.toLowerCase().includes(query));
                })
                .map(([diagId, diagInfo]) => ({ 
                    diagId, 
                    ...diagInfo 
                }));
            
            matches = [...matches, ...diagnosticMatches];
        }
        
        // Remove loading indicator
        loadingIndicator.remove();
        
        if (matches.length === 0) {
            const noResults = document.createElement('div');
            noResults.className = 'no-results';
            noResults.textContent = 'No matches found.';
            resultsContainer.appendChild(noResults);
            return;
        }
        
        // Display results
        const resultsTitle = document.createElement('h3');
        resultsTitle.textContent = `Search Results (${matches.length})`;
        resultsContainer.appendChild(resultsTitle);
        
        // Set up pagination for search results
        searchResults = matches;
        searchCurrentPage = 1;
        searchTotalPages = Math.ceil(searchResults.length / searchItemsPerPage);
        
        // Display first page of results
        await displayPageResults(resultsContainer);
        
    } catch (error) {
        console.error('Search error:', error);
        loadingIndicator.remove();
        
        const errorMessage = document.createElement('div');
        errorMessage.className = 'error-message';
        errorMessage.textContent = `Search error: ${error.message}`;
        resultsContainer.appendChild(errorMessage);
    }
}

// 创建一个生成分页控件的辅助函数，避免代码重复
function createPaginationUI(container, sectionTitle, position = 'top') {
    const isTop = position === 'top';
    const wrapperClass = isTop ? 'td-pagination-top' : 'td-pagination-bottom';
    const infoClass = isTop ? 'td-range-info-top' : 'td-range-info-bottom';
    const controlsClass = isTop ? 'td-pagination-controls-top' : 'td-pagination-controls-bottom';
    
    // 创建分页信息包装器
    const paginationWrapper = document.createElement('div');
    paginationWrapper.className = `pagination-wrapper ${wrapperClass}`;
    container.appendChild(paginationWrapper);
    
    // 添加分页信息
    const rangeInfo = document.createElement('div');
    rangeInfo.className = `search-results-info ${infoClass}`;
    const startItem = (tdCurrentPage - 1) * tdItemsPerPage + 1;
    const endItem = Math.min(tdCurrentPage * tdItemsPerPage, filteredTDDiagnostics.length);
    rangeInfo.textContent = `Showing diagnostics ${startItem}-${endItem} of ${filteredTDDiagnostics.length}`;
    paginationWrapper.appendChild(rangeInfo);
    
    // 创建分页控件
    const paginationDiv = document.createElement('div');
    paginationDiv.className = `pagination-controls ${controlsClass}`;
    
    // 创建上一页按钮
    const prevButton = document.createElement('button');
    prevButton.className = 'pagination-btn prev-btn';
    prevButton.disabled = tdCurrentPage <= 1;
    prevButton.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <path d="M15 18l-6-6 6-6"/>
        </svg>
        <span>Previous</span>
    `;
    prevButton.addEventListener('click', async () => {
        if (tdCurrentPage > 1) {
            tdCurrentPage--;
            await displayTDPage(container);
            // 滚动到诊断区域顶部
            sectionTitle.scrollIntoView({ behavior: 'smooth' });
        }
    });
    
    // 创建下一页按钮
    const nextButton = document.createElement('button');
    nextButton.className = 'pagination-btn next-btn';
    nextButton.disabled = tdCurrentPage >= tdTotalPages;
    nextButton.innerHTML = `
        <span>Next</span>
        <svg xmlns="http://www.w3.org/2000/svg" width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
            <path d="M9 18l6-6-6-6"/>
        </svg>
    `;
    nextButton.addEventListener('click', async () => {
        if (tdCurrentPage < tdTotalPages) {
            tdCurrentPage++;
            await displayTDPage(container);
            // 滚动到诊断区域顶部
            sectionTitle.scrollIntoView({ behavior: 'smooth' });
        }
    });
    
    // 页码信息
    const pageInfo = document.createElement('div');
    pageInfo.className = 'page-info';
    pageInfo.innerHTML = `${tdCurrentPage} of ${tdTotalPages}`;
    
    // 添加元素到分页控件
    paginationDiv.appendChild(prevButton);
    paginationDiv.appendChild(pageInfo);
    paginationDiv.appendChild(nextButton);
    
    // 添加分页控件到包装器
    paginationWrapper.appendChild(paginationDiv);
    
    return paginationWrapper;
} 