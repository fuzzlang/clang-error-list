
// Function declarations for testing variants
void foo();
void bar();

#pragma omp begin declare variant match(implementation = {vendor(score(2) : llvm)})
void foo() {
    // Implementation of foo
}

#pragma omp declare variant(foo) match(implementation = {vendor(score(2) : llvm)})
void bar() {
    // Implementation of bar
}

// This will trigger the expected error due to duplicate nested traits
#pragma omp declare variant(foo) match(implementation = {vendor(score(2) : llvm)})

// required code block for OpenMP directive
{
    // some code logic
} 
