
class Incomplete; // Forward declaration of an incomplete class

void exampleFunction() {
    Incomplete *c; // Pointer to an incomplete class type
    switch (*c) { // expected-error{{incomplete class type}}
        // Case labels would go here
    }
}
