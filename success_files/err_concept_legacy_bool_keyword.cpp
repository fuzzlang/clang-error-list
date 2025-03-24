
// expected-error@-1{{use of undeclared identifier 'wor'; did you mean 'word'?}}
// expected-note@-2{{'word' declared here}}

template<typename T> concept bool C7 = true;

void exampleFunction() {
    bool result = wor; // This will trigger the expected error
}
