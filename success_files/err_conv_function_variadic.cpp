
class MyClass {
public:
    operator float(...) const; // expected-error{{conversion function cannot be variadic}}
};
