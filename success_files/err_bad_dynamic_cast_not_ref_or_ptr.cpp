
struct A {};

class Base {
public:
    virtual void f();
};

class Derived : public Base {};

template<typename T, typename U>
struct DynamicCast0 {
    void f(T t) {
        (void)dynamic_cast<U>(t); // expected-error{{invalid target type 'A' for dynamic_cast; target type must be a reference or pointer type to a defined class}}
    }
};

template struct DynamicCast0<Base*, A>; // expected-note{{instantiation}}
