document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('error-form');
    const previewButton = document.getElementById('preview-button');
    const backButton = document.getElementById('back-to-form');
    const formSection = document.getElementById('add-error');
    const previewSection = document.getElementById('preview-section');
    const previewContainer = document.getElementById('preview-container');
    
    // Preview functionality
    previewButton.addEventListener('click', function(e) {
        e.preventDefault();
        
        // Get form data
        const errorData = {
            id: document.getElementById('error-id').value,
            description: document.getElementById('error-description').value,
            exampleCode: document.getElementById('error-example').value,
            explanation: document.getElementById('error-explanation').value,
            fixedCode: document.getElementById('error-fixed').value
        };
        
        // Validate all fields are filled
        for (const key in errorData) {
            if (!errorData[key]) {
                alert('Please fill in all fields');
                return;
            }
        }
        
        // Create preview
        previewContainer.innerHTML = '';
        const errorCard = createErrorCard(errorData);
        previewContainer.appendChild(errorCard);
        
        // Show preview section, hide form
        formSection.style.display = 'none';
        previewSection.style.display = 'block';
        
        // Apply code highlighting
        document.querySelectorAll('pre code').forEach(block => {
            hljs.highlightElement(block);
        });
    });
    
    // Return to form
    backButton.addEventListener('click', function() {
        previewSection.style.display = 'none';
        formSection.style.display = 'block';
    });
    
    // Submit form
    form.addEventListener('submit', function(e) {
        e.preventDefault();
        
        // Get form data
        const errorData = {
            id: document.getElementById('error-id').value,
            description: document.getElementById('error-description').value,
            exampleCode: document.getElementById('error-example').value,
            explanation: document.getElementById('error-explanation').value,
            fixedCode: document.getElementById('error-fixed').value
        };
        
        // In a real application, this would send data to the server
        // Since this is a frontend demo, we just display the data
        const jsonOutput = JSON.stringify(errorData, null, 2);
        alert('Error data ready to save:\n\n' + jsonOutput);
        
        // Clear form
        form.reset();
    });
    
    // Create error card function (same as main page)
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
}); 