
template <typename Ts>
struct O2 : protected Ts { // expected-note {{declared protected here}}
    using Ts::operator();
    O2(Ts ts) : Ts(ts) {}
};

void f() {
    int x;
    auto L1 = [=](this auto&& self) { (void)&x; };
    O2{L1}(); // expected-error {{must derive publicly from the lambda}}
}
