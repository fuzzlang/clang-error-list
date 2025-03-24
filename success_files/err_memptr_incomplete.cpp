
struct S;

void example() {
    int S::*foo; // expected-error {{member pointer has incomplete base type 'S'}}
}
