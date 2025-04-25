/**
 * Common components and functionality for Clang Error Index website
 */

document.addEventListener('DOMContentLoaded', function() {
    // Initialize common components
    initializeCommonComponents();
    
    // Initialize back to top button
    initBackToTopButton();
    
    // Initialize search functionality
    initializeSearch();
    
    // Highlight current active navigation item
    highlightActiveNavItem();
});

/**
 * Highlight the current active navigation item
 */
function highlightActiveNavItem() {
    const currentPath = window.location.pathname;
    const navLinks = document.querySelectorAll('nav ul li a');
    
    navLinks.forEach(link => {
        const linkPath = link.getAttribute('href');
        
        // Check if it's the current page
        if (currentPath.endsWith(linkPath) || 
            (currentPath.endsWith('/') && linkPath === 'index.html')) {
            link.classList.add('active');
        } else {
            link.classList.remove('active');
        }
    });
}

/**
 * Initialize common components like footer
 */
function initializeCommonComponents() {
    // Add footer to the page
    addFooter();
    
    // Add back to top button
    addBackToTopButton();
    
    // Set header title link
    setHeaderTitleLink();
}

/**
 * Initialize search functionality
 */
function initializeSearch() {
    const searchInput = document.getElementById('searchInput');
    const searchButton = document.getElementById('searchButton');
    
    if (!searchInput || !searchButton) {
        return;
    }
    
    // Clear existing event listeners (to avoid duplicates)
    searchButton.replaceWith(searchButton.cloneNode(true));
    
    // Get fresh references after replacing
    const newSearchButton = document.getElementById('searchButton');
    
    // Check if we're on the error-list.html page
    const isErrorListPage = window.location.pathname.endsWith('error-list.html');
    
    // Add event listeners
    newSearchButton.addEventListener('click', function() {
        handleSearch(searchInput.value, isErrorListPage);
    });
    
    searchInput.addEventListener('keypress', function(e) {
        if (e.key === 'Enter') {
            handleSearch(searchInput.value, isErrorListPage);
        }
    });
    
    // Check for search parameter in URL when on error-list page
    if (isErrorListPage) {
        const urlParams = new URLSearchParams(window.location.search);
        const searchQuery = urlParams.get('q');
        
        if (searchQuery) {
            // Set the search input value
            searchInput.value = searchQuery;
            
            // Perform the search if performSearch function exists
            if (typeof performSearch === 'function') {
                setTimeout(() => performSearch(searchQuery), 500);
            }
        }
    }
}

/**
 * Handle search action - either perform search or redirect to error-list.html
 */
function handleSearch(query, isErrorListPage) {
    if (!query.trim()) {
        return;
    }
    
    if (isErrorListPage) {
        // We're on the error-list page, perform the search
        if (typeof performSearch === 'function') {
            performSearch(query);
        } else {
            console.error('performSearch function not found');
        }
    } else {
        // Redirect to error-list.html with search query as parameter
        window.location.href = `error-list.html?q=${encodeURIComponent(query)}`;
    }
}

/**
 * Add copyright footer to the page
 */
function addFooter() {
    // Check if footer already exists
    if (document.querySelector('footer')) {
        return;
    }
    
    // Create footer element
    const footer = document.createElement('footer');
    
    // Set footer content
    footer.innerHTML = `
    <div class="container">
        <p>&copy; 2025 Fuzzlang Team. All rights reserved.</p>
        <p>This is an unofficial resource and is not affiliated with the LLVM Project or Clang.</p>
    </div>
    `;
    
    // Add footer to the document
    document.body.appendChild(footer);
}

/**
 * Add back to top button to the page
 */
function addBackToTopButton() {
    // Check if back to top button already exists
    if (document.getElementById('back-to-top')) {
        return;
    }
    
    // Create back to top button
    const backToTopBtn = document.createElement('div');
    backToTopBtn.id = 'back-to-top';
    backToTopBtn.className = 'back-to-top-btn';
    
    // Set button content (up arrow)
    backToTopBtn.innerHTML = `
    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
        <polyline points="18 15 12 9 6 15"></polyline>
    </svg>
    `;
    
    // Add CSS styles for the button
    addBackToTopStyles();
    
    // Add button to the document
    document.body.appendChild(backToTopBtn);
}

/**
 * Add CSS styles for back to top button
 */
function addBackToTopStyles() {
    // Check if styles are already added
    if (document.getElementById('back-to-top-styles')) {
        return;
    }
    
    // Create style element
    const style = document.createElement('style');
    style.id = 'back-to-top-styles';
    
    // Set CSS styles
    style.textContent = `
    .back-to-top-btn {
        position: fixed;
        bottom: 30px;
        right: 30px;
        width: 50px;
        height: 50px;
        border-radius: 50%;
        background-color: #4a6bdf;
        color: white;
        display: flex;
        align-items: center;
        justify-content: center;
        cursor: pointer;
        opacity: 0;
        visibility: hidden;
        transition: all 0.3s ease;
        box-shadow: 0 4px 10px rgba(0, 0, 0, 0.2);
        z-index: 1000;
    }
    
    .back-to-top-btn:hover {
        background-color: #3a5bcf;
        transform: translateY(-5px);
        box-shadow: 0 6px 15px rgba(0, 0, 0, 0.25);
    }
    
    .back-to-top-btn.visible {
        opacity: 1;
        visibility: visible;
    }
    
    @media (max-width: 768px) {
        .back-to-top-btn {
            bottom: 20px;
            right: 20px;
            width: 45px;
            height: 45px;
        }
    }
    
    .home-link {
        text-decoration: none;
        color: inherit;
    }
    
    .home-link:hover {
        text-decoration: underline;
    }
    `;
    
    // Add style to document head
    document.head.appendChild(style);
}

/**
 * Make header title clickable and link to home page
 */
function setHeaderTitleLink() {
    const headerTitle = document.querySelector('header h1');
    
    // If header title already has a link, skip
    if (headerTitle && !headerTitle.querySelector('a')) {
        const titleText = headerTitle.textContent;
        headerTitle.innerHTML = `<a href="index.html" class="home-link">${titleText}</a>`;
    }
}

/**
 * Initialize back to top button functionality
 */
function initBackToTopButton() {
    const backToTopBtn = document.getElementById('back-to-top');
    const header = document.querySelector('header');
    
    if (!backToTopBtn || !header) {
        return;
    }
    
    // Detect page scroll to show/hide button
    window.addEventListener('scroll', function() {
        const headerBottom = header.getBoundingClientRect().bottom;
        
        if (headerBottom < 0) {
            backToTopBtn.classList.add('visible');
        } else {
            backToTopBtn.classList.remove('visible');
        }
    });
    
    // Click button to return to top
    backToTopBtn.addEventListener('click', function() {
        window.scrollTo({
            top: 0,
            behavior: 'smooth'
        });
    });
} 