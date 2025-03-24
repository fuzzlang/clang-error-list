
// expected-error@-1 {{no matching function for call to 'f'}}
// expected-note@#cwg115-f {{candidate template ignored: couldn't infer template argument 'T'}}

namespace cwg115 {
    template<typename T> void f(T);
    template<typename T> void g(T);
    void h() {
        (void)&f; // expected-error@-1 {{address of overloaded function 'f' cannot be cast to type 'void'}}
    }
}
