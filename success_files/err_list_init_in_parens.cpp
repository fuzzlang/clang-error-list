
template<typename T> void reproduce_error() {
    T var = {0};  // Testing list initialization with single-element list.

    struct StructA { T var; };
    StructA sa{0};  // Testing list initialization with structure.

    StructA saNested{{0}};  // Testing nested brace initialization.

    struct StructB { T var = {0}; } sb; // Testing default member initializer.

    struct StructC { T var; StructC() : var({0}) {} }; // Testing constructor member initializer list.
}

void test() {
    // Instantiate template to trigger errors
    reproduce_error<int>();  // expected-error {{cannot initialize}}
}

