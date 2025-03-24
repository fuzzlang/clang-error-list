
void func1(void);

[[noreturn(12)]] void func4(void); // expected-error {{attribute 'noreturn' cannot have an argument list}}
[[noreturn]] int not_a_func; // expected-error {{'noreturn' attribute only applies to functions}}
void func5(void) [[noreturn]]; // expected-error {{'noreturn' attribute cannot be applied to types}}

void func1(void) {
  // Implement function logic if necessary
}
