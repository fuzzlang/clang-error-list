
struct G {
    G(int); // Constructor takes an int
};

struct H : G {
    using G::G; // Inherit constructors from G
    G g; // Member that has no default constructor
};

void test() {
    H h(0); // expected-error@-1 {{constructor inherited by 'H' from base class 'G' is implicitly deleted}}
}
