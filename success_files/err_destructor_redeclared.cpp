
struct F {
    ~F(); // expected-error {{destructor cannot be redeclared}}
    ~F(); // Second declaration of the destructor
};
