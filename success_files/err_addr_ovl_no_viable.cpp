
namespace Deduce1 {
    template <typename T> auto f() { return 0; } // expected-note {{couldn't infer template argument 'T'}}
    template<typename T> void g(T(*)()); // expected-note 2{{candidate}}
    void h() {
        int (*r)() = f; // expected-error {{does not match}}
    }
}
