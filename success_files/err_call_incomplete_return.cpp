
struct A; // expected-note {{forward declaration of 'A'}}

A f(); // expected-note {{'f' declared here}}

typedef A (*Func)();

void g() {
    f(); // expected-error {{calling 'f' with incomplete return type 'A'}}

    Func fp;
    fp(); // expected-error {{calling function with incomplete return type 'A'}}
}
