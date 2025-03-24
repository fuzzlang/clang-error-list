
struct N {
    struct F {
        ~F();
    };
};

struct G {
    ~G();
};

void func() {
    N f;
    f.N::F::~F(); // This is valid
    f.N::F::~G(); // expected-error@-1 {{ISO C++ requires the name after '::~' to be found in the same scope as the name before '::~'}}
}
