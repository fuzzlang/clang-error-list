
namespace CaptureIncomplete {
    struct Incomplete; // expected-note 2{{forward decl}}
    void g(const Incomplete &a);
    void f(Incomplete &a) {
        (void) [a] {}; // expected-error {{incomplete}}
    }
}
