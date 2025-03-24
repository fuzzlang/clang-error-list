
class MyClass {
public:
    static const int vs = 5;
    static const int nci = vs; // expected-error {{in-class initializer for static data member is not a constant expression}}
    static const int vi = 0;
    static const volatile int cvi = 0; // ok, illegal in C++11
};
