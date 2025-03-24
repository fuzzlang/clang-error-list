
struct A { };
struct B : A { };

bool test(A* a) {
    return dynamic_cast<B *>(a) != 0; // expected-error {{use of dynamic_cast requires -frtti}}
}
