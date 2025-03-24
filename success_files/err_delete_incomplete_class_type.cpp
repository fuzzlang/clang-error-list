
struct A; // expected-note {{forward declaration}}
extern A x; 
void f() { 
    delete x; // expected-error {{deleting incomplete class type}} 
}
