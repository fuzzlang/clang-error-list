
struct S {};

template <auto T>
struct A {};

template <auto T>
A<*T> operator *() { return {}; } // expected-error {{overloaded 'operator*' must have at least one parameter of class or enumeration type}}

int main() {
    S s;
    int c = s * 1; // expected-error
}
