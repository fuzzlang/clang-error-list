
void ReturnsVoid(); // expected-note {{'ReturnsVoid' declared here}}
struct TestDestructor {
    ~TestDestructor() {
        [[clang::musttail]]   // expected-note {{tail call required by 'musttail' attribute here}}
        return ReturnsVoid(); // expected-error {{destructor '~TestDestructor' must not return void expression}}  // expected-error {{cannot perform a tail call from a destructor}}
    }
};
