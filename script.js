document.addEventListener('DOMContentLoaded', function() {
    const searchInput = document.getElementById('searchInput');
    const searchButton = document.getElementById('searchButton');
    
    // Search functionality
    function performSearch() {
        const searchTerm = searchInput.value.toLowerCase();
        const errorCards = document.querySelectorAll('.error-card');
        
        errorCards.forEach(card => {
            const errorCode = card.id.toLowerCase();
            const errorText = card.textContent.toLowerCase();
            
            if (errorCode.includes(searchTerm) || errorText.includes(searchTerm)) {
                card.style.display = 'block';
            } else {
                card.style.display = 'none';
            }
        });
        
        // Scroll to error list section
        document.getElementById('error-list').scrollIntoView({ behavior: 'smooth' });
    }
    
    // Search on button click
    searchButton.addEventListener('click', performSearch);
    
    // Search on Enter key press
    searchInput.addEventListener('keyup', function(event) {
        if (event.key === 'Enter') {
            performSearch();
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
                
                // Check for hash links again after loading
                if (window.location.hash) {
                    const targetElement = document.querySelector(window.location.hash);
                    if (targetElement) {
                        targetElement.scrollIntoView({ behavior: 'smooth' });
                        targetElement.classList.add('highlight');
                        setTimeout(() => targetElement.classList.remove('highlight'), 2000);
                    }
                }
            })
    }
    
    // Fallback function with hardcoded errors
    function loadHardcodedErrors() {
        console.log('Falling back to hardcoded errors');
        const errorListContainer = document.getElementById('error-list-container');
        errorListContainer.innerHTML = ''; // Clear existing content
        
        // Hardcoded error data
        const errors = [
            {
                id: "err_decomp_decl_context",
                description: "This error occurs when structured bindings (C++17 feature) are used in an invalid context. Structured bindings can only be used in specific contexts such as local variable declarations, for-range init-statements, and condition variables.",
                exampleCode: "struct S { int a, b, c; };\n\nnamespace InvalidContext {\n    class A {\n        auto [a, b, c] = S(); // expected-error {{not permitted in this context}}\n    };\n}",
                explanation: "In this example, the error occurs because structured bindings are being used as a class member, which is not allowed. Structured bindings can only be used for local variables, not for class members.",
                fixedCode: "struct S { int a, b, c; };\n\nnamespace ValidContext {\n    class A {\n        S s;  // Use a regular member variable\n        \n        void method() {\n            auto [a, b, c] = S();  // Valid: local variable in method\n        }\n    };\n}"
            },
            {
                id: "err_expected_semi_after_declaration",
                description: "This error occurs when a semicolon is missing after a declaration. In C and C++, declarations must be terminated with a semicolon.",
                exampleCode: "void function() {\n    int x = 10    // expected-error {{expected ';' after declaration}}\n    int y = 20;\n}",
                explanation: "The error occurs because the declaration of variable 'x' is not terminated with a semicolon. In C and C++, all declarations must end with a semicolon.",
                fixedCode: "void function() {\n    int x = 10;   // Added semicolon\n    int y = 20;\n}"
            },
            {
                id: "err_undeclared_var_use",
                description: "This error occurs when a variable is used without being declared first. In C and C++, all variables must be declared before they can be used.",
                exampleCode: "void function() {\n    value = 42;  // expected-error {{use of undeclared identifier 'value'}}\n    \n    for (i = 0; i < 10; i++) {  // expected-error {{use of undeclared identifier 'i'}}\n        // ...\n    }\n}",
                explanation: "The error occurs because the variables 'value' and 'i' are being used without being declared first. In C and C++, all variables must be declared before they can be used in the scope where they are referenced.",
                fixedCode: "void function() {\n    int value;  // Declare the variable\n    value = 42;\n    \n    for (int i = 0; i < 10; i++) {  // Declare i in the for loop\n        // ...\n    }\n}"
            }
        ];
        
        // Create error cards for each hardcoded error
        errors.forEach(errorData => {
            const errorCard = createErrorCard(errorData);
            errorListContainer.appendChild(errorCard);
        });
        
        // Apply code highlighting
        document.querySelectorAll('pre code').forEach(block => {
            hljs.highlightElement(block);
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
    
    // Load error data when page loads
    loadErrorData();
}); 