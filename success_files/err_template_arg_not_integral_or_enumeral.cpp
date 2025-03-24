
template<int N> struct A; // expected-note {{template parameter is declared here}}

class X {
public:
    X();
    X(int, int);
    operator int() const;
};

int main() {
    A<X(17, 42)> *a11; // expected-error{{non-type template argument of type 'X' must have an integral or enumeration type}}
    return 0;
}
