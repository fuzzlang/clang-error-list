
struct S {
    void f() {
        auto lambda = [this, &this] {}; // expected-error {{'this' cannot be captured by reference}}
    }
};
