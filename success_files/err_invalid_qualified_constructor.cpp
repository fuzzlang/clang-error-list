
class Foo {
public:
    Foo(long) const; // expected-error{{'const' qualifier is not allowed on a constructor}}
};
