
constexpr int Fun() { 
    return; // expected-error {{non-void constexpr function 'Fun' should return a value}} 
}
