
namespace cwg641 {
    struct xyz {
        xyz(); // constructor
        xyz(xyz&); // copy constructor
        operator xyz &() = delete; // conversion function to lvalue reference
    };

    template<typename T>
    void use(T&); // function that expects an lvalue reference

    void test() {
        use<xyz>(xyz()); // expected-error@-1 {{no matching function for call to 'use'}}
                         //   expected-note@#cwg641-use {{candidate function template not viable: expects an lvalue for 1st argument}}
        use<const xyz>(xyz()); // expected cxx98-error@-1 {{no viable constructor copying parameter of type 'xyz'; C++98 requires a copy constructor when binding a reference to a temporary}}
    }
}
