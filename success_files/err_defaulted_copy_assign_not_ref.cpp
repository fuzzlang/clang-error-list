
class A {
public:
    A &operator=(A) const = default; // expected-error {{must be an lvalue reference}}
};
