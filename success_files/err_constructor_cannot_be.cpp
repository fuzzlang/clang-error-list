
class Foo {
public:
    static Foo(short a, short b); // expected-error{{constructor cannot be declared 'static'}}
};
