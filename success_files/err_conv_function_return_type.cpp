
class A {
public:
    void operator bool(int, ...) const; // expected-error{{conversion function cannot have a return type}}
};
