
class Foo {
public:
    mutable void mfn(); // expected-error {{'mutable' cannot be applied to functions}}
};
