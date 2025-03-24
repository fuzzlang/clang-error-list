
struct A {
    explicit operator int(); // expected-note{{conversion to integral type}}
};

void x() {
    switch(A()) { // expected-error{{explicit conversion to}}
    }
}
