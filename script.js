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
            'tdfiles/DiagnosticFrontendKinds.td'
            // Reduced number of files to load initially
        ];

        console.log('Loading diagnostic files...');

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
        // Optimized regex matching
        const pattern = /def\s+(\w+)\s*:\s*(Error|Warning|Note|Remark|Extension|ExtWarn)<\s*"([^"]+(?:\s*"[^"]*)*?)"\s*>/g;
        let match;

        while ((match = pattern.exec(content)) !== null) {
            const diagId = match[1];
            const diagType = match[2];
            // Simplify string processing
            let messageTemplate = match[3].replace(/"\s*"/g, '').replace(/\s+/g, ' ').trim();
            
            this.diagnostics.set(diagId, {
                template: messageTemplate,
                type: diagType,
                fileName: fileName
            });
            this.fileMapping.set(diagId, fileName);
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
        
        // First try exact matches in expanded templates
        this.expandedTemplates.forEach((variants, diagId) => {
            for (const variant of variants) {
                if (variant.toLowerCase().includes(queryLower)) {
                    const diagInfo = this.diagnostics.get(diagId);
                    if (diagInfo) {
                        results.push({
                            diagId,
                            template: diagInfo.template,
                            type: diagInfo.type,
                            fileName: this.fileMapping.get(diagId) || "Unknown file",
                            similarity: 1.0,
                            matchType: "expanded",
                            matchedVariant: variant
                        });
                        return;
                    }
                }
            }
        });
        
        // If no expanded matches, try other matching strategies
        if (results.length === 0) {
            // Limit the number of diagnostics to check for performance
            const MAX_CHECKS = 1000;
            let checked = 0;
            
            // Try direct matching on diagnostic IDs first
            this.diagnostics.forEach((diagInfo, diagId) => {
                if (checked >= MAX_CHECKS) return;
                checked++;
                
                if (diagId.toLowerCase().includes(queryLower)) {
                    results.push({
                        diagId,
                        template: diagInfo.template,
                        type: diagInfo.type,
                        fileName: this.fileMapping.get(diagId) || "Unknown file",
                        similarity: 0.9,
                        matchType: "id"
                    });
                    return;
                }
                
                // Then try template matching
                const templateLower = diagInfo.template.toLowerCase();
                if (templateLower.includes(queryLower)) {
                    results.push({
                        diagId,
                        template: diagInfo.template,
                        type: diagInfo.type,
                        fileName: this.fileMapping.get(diagId) || "Unknown file",
                        similarity: 0.8,
                        matchType: "template"
                    });
                    return;
                }
                
                // Finally try fuzzy matching
                const similarity = this.calculateSimilarity(queryLower, templateLower);
                if (similarity > threshold) {
                    results.push({
                        diagId,
                        template: diagInfo.template,
                        type: diagInfo.type,
                        fileName: this.fileMapping.get(diagId) || "Unknown file",
                        similarity,
                        matchType: "fuzzy"
                    });
                }
            });
        }
        
        // Sort by similarity
        results.sort((a, b) => b.similarity - a.similarity);
        return results.slice(0, 10); // Limit to top 10 results
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
}

// Perform search function
function performSearch(query) {
    query = query.toLowerCase().trim();
    if (!query) return;
    
    console.log('Searching for:', query);
    
    // First, search in existing error cards
    const errorItems = document.querySelectorAll('.error-card');
    let foundCount = 0;
    
    errorItems.forEach(item => {
        const id = item.id.toLowerCase();
        const content = item.textContent.toLowerCase();
        
        if (id.includes(query) || content.includes(query)) {
            item.style.display = 'block';
            foundCount++;
        } else {
            item.style.display = 'none';
        }
    });
    
    // Display search results info
    updateSearchResultsInfo(query, foundCount);
    
    // If no results found in existing cards, try to search in TD files
    if (foundCount === 0) {
        searchInTDFiles(query);
    } else {
        // Scroll to error list section
        document.getElementById('error-list').scrollIntoView({ behavior: 'smooth' });
    }
}

// Update search results info
function updateSearchResultsInfo(query, foundCount) {
    const resultsInfo = document.getElementById('search-results-info') || document.createElement('div');
    resultsInfo.id = 'search-results-info';
    resultsInfo.className = 'search-results-info';
    
    if (query !== '') {
        resultsInfo.textContent = `Found ${foundCount} result${foundCount !== 1 ? 's' : ''} for "${query}"`;
    } else {
        resultsInfo.textContent = '';
    }
    
    const errorListSection = document.getElementById('error-list');
    if (!document.getElementById('search-results-info')) {
        errorListSection.insertBefore(resultsInfo, document.getElementById('error-list-container'));
    }
    
    // Scroll to error list section
    errorListSection.scrollIntoView({ behavior: 'smooth' });
}

// Search in TD files
function searchInTDFiles(query) {
    console.log('Searching in TD files');
    
    // Make sure the parser is initialized
    window.diagnosticParser.initialize().then(() => {
        const results = window.diagnosticParser.searchDiagnostic(query);
        
        if (results.length > 0) {
            displayTDMatches(results, query);
        } else {
            // Update search results info to show no results
            updateSearchResultsInfo(query, 0);
            
            // Scroll to error list section
            document.getElementById('error-list').scrollIntoView({ behavior: 'smooth' });
        }
    });
}

// Display TD matches
async function displayTDMatches(results, query) {
    console.log('Displaying TD matches:', results);
    
    const errorListContainer = document.getElementById('error-list-container');
    errorListContainer.innerHTML = ''; // Clear existing content
    
    const fragment = document.createDocumentFragment();
    
    // Process each result
    for (const diagnostic of results) {
        // Try to load corresponding JSON file
        const jsonData = await tryLoadJsonForDiagnostic(diagnostic.diagId);
        
        // Create appropriate card
        const card = jsonData ? 
            createEnhancedErrorCard(jsonData, diagnostic) : 
            createDiagnosticCard(diagnostic);
        
        fragment.appendChild(card);
    }
    
    errorListContainer.appendChild(fragment);
    
    // Apply syntax highlighting
    document.querySelectorAll('pre code').forEach(block => {
        hljs.highlightElement(block);
    });
    
    // Update search results info
    updateSearchResultsInfo(query, results.length);
    
    // Scroll to error list section
    document.getElementById('error-list').scrollIntoView({ behavior: 'smooth' });
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
        <h3>${errorData.id}</h3>
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
        <h3>${diagnostic.diagId}</h3>
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
        <h3>${errorData.id}</h3>
        <div class="error-description">
            <p>${errorData.description}</p>
            ${diagnosticInfo ? `
            <p><strong>Message Template:</strong> ${escapeHtml(diagnosticInfo.template)}</p>
            <p><strong>Type:</strong> ${diagnosticInfo.type}</p>
            <p><strong>Source:</strong> ${diagnosticInfo.fileName.split('/').pop()}</p>
            ` : ''}
        </div>
        <div class="code-example">
            <h4>Example Code:</h4>
            <pre><code class="language-cpp">${escapeHtml(errorData.exampleCode)}</code></pre>
        </div>
        <div class="error-explanation">
            <h4>Explanation:</h4>
            <p>${errorData.explanation}</p>
        </div>
        ${hasFixedCode ? `
        <div class="fix-example">
            <h4>Fixed Code:</h4>
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