
// Module B Interface
module;

// Declaration or usage of module 'B'
export module B;

// Import 'B' in its own implementation, leading to the specified error
import B; // expected-error {{import of module 'B' appears within its own implementation}}

// Definitions and implementation of module 'B' can go here
int someFunctionB() {
    return 42;
}
