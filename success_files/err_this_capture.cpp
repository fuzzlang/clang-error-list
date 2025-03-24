
struct X {
    void f(int) {}
    
    void foo() {
        auto L = [](auto a) { f(a); }; //expected-error{{this}}
        L(3);
    }
};

int run = (X{}.foo(), 0);
