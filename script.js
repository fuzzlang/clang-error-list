document.addEventListener('DOMContentLoaded', function() {
    console.log('DOM loaded, loading error data...');
    loadErrorData();
    
    // 搜索功能
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
        }, 1000); // Increased timeout to allow errors to load
    }
});

// 执行搜索
function performSearch(query) {
    query = query.toLowerCase();
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
    
    // 显示搜索结果信息
    const resultsInfo = document.getElementById('search-results-info') || document.createElement('div');
    resultsInfo.id = 'search-results-info';
    resultsInfo.className = 'search-results-info';
    
    if (query.trim() !== '') {
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

// Load error data function
function loadErrorData() {
    console.log('Attempting to load error data...');
    
    // First try to fetch the index file
    fetch('errors/index.json')
        .then(response => {
            console.log('Response status:', response.status);
            if (!response.ok) {
                throw new Error(`Network response was not ok: ${response.status}`);
            }
            return response.json();
        })
        .then(errorIndex => {
            console.log('Successfully loaded error index:', errorIndex);
            
            // Get error list container
            const errorListContainer = document.getElementById('error-list-container');
            errorListContainer.innerHTML = ''; // Clear existing content
            
            if (!errorIndex.errors || errorIndex.errors.length === 0) {
                errorListContainer.innerHTML = '<div class="error-message">No errors found in the index.</div>';
                return Promise.resolve();
            }
            
            // Load each error
            const promises = errorIndex.errors.map(errorId => {
                console.log(`Loading error: ${errorId}`);
                return fetch(`errors/${errorId}.json`)
                    .then(response => {
                        if (!response.ok) {
                            throw new Error(`Failed to load ${errorId}: ${response.status}`);
                        }
                        return response.json();
                    })
                    .then(errorData => {
                        console.log(`Successfully loaded error: ${errorId}`);
                        // Create error card and add to container
                        const errorCard = createErrorCard(errorData);
                        errorListContainer.appendChild(errorCard);
                    })
                    .catch(error => {
                        console.error(`Error loading ${errorId}:`, error);
                        return null; // Continue with other errors
                    });
            });
            
            // After all errors are loaded, apply code highlighting and check for hash links
            return Promise.all(promises);
        })
        .then(() => {
            console.log('All errors loaded, applying highlighting');
            // Apply code highlighting to all code blocks
            document.querySelectorAll('pre code').forEach(block => {
                hljs.highlightElement(block);
            });
            
            // Check for hash links after loading
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
        })
        .catch(error => {
            console.error('Error loading error data:', error);
            const errorListContainer = document.getElementById('error-list-container');
            errorListContainer.innerHTML = `<div class="error-message">Error loading data: ${error.message}</div>`;
        });
}

// Create error card function
function createErrorCard(errorData) {
    const card = document.createElement('div');
    card.className = 'error-card';
    card.id = errorData.id;
    
    card.innerHTML = `
        <h3>${errorData.id}</h3>
        <div class="error-description">
            <p>${errorData.description}</p>
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