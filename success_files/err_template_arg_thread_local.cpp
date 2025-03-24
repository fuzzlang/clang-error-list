
namespace non_type_tmpl_param {
    __thread int ti = 100; // thread-local storage

    template <int& N> struct X2 {}; // Expected error for non-type template argument

    void test() {
        X2<ti> x2d_addr; // expected-error {{refers to thread-local object}} cxx17-error {{non-type template argument is not a constant expression}}
    }
}
