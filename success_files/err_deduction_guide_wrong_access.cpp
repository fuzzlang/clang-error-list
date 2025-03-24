
template<typename T>
struct A {
    template<typename U> A(U); // Constructor
    template<typename U> A(U, int); // Constructor
};

struct B {
    template<typename T> struct Public; // expected-note {{declared public}}
    Public(float) -> Public<float>;
protected: // expected-note {{declared protected by intervening access specifier}}
    template<typename T> struct Protected; // expected-note {{declared protected}}
    Protected(float) -> Protected<float>;
    Public(int) -> Public<int>; // expected-error {{different access}}
private: // expected-note {{declared private by intervening access specifier}}
    template<typename T> struct Private; // expected-note {{declared private}}
    Protected(int) -> Protected<int>; // expected-error {{different access}}
};
