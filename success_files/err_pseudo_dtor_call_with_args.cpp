
struct A {};

enum Foo { F };
typedef Foo Bar; // expected-note{{type 'Bar' (aka 'Foo') found by destructor name lookup}}

void f(A* a, Foo *f) {
    a->~A();
    f->Bar::~Bar(17, 42); // expected-error{{cannot have any arguments}}
}
