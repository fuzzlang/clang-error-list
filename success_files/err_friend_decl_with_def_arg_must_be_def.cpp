
struct A {
    // expected-error@-1 {{friend declaration specifying a default argument must be the only declaration}}
    //   expected-note@#cwg136-g {{previous declaration is here}}
    friend void h(int, int, int = 0);
    friend void h(int, int); // Previous declaration
};
