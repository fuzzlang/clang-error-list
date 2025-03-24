
class MyClass {
public:
    static const int Divisor = 0; // This will cause division by zero.
    static const int value = 10 / Divisor; // expected-error{{in-class initializer for static data member is not a constant expression}}
};
