
struct O {
    int operator()(O) = delete; // expected-note {{explicitly marked deleted}} expected-note {{explicitly deleted}}
};

void f() {
    O o;
    o(o); // expected-error {{call to deleted function call operator in type 'O': deleted (O, ())}} 
          // expected-error {{attempt to use a deleted function: deleted (O, ())}}
}
