
typedef int INT;

class Foo {
    Foo();
    (Foo)(float) { }
    explicit Foo(int); // expected-note {{previous declaration is here}}
    Foo(const Foo&);
    
    ((Foo))(INT); // expected-error{{cannot be redeclared}}
};

Foo::Foo(const Foo&) { }

int main() {
    return 0;
}
