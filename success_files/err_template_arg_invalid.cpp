
namespace non_type_tmpl_param {
    template<int* N> struct X0 { };

    void test() {
        int *iptr = nullptr; // Initialization of pointer variable
        X0<(int*)1> x0c; // expected-error{{non-type template argument '(int *)1' is invalid}}
    }
}
