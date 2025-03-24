
[[noreturn(12)]] void func4(void); // expected-error {{attribute 'noreturn' cannot have an argument list}}

void test() {
    func4();
}
