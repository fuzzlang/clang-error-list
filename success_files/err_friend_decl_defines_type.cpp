
class A {
    friend class B {}; // expected-error {{cannot define a type in a friend declaration}}
};
