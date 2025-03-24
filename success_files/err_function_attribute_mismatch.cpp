
void foo6(); // expected-error {{function declared with 'no_caller_saved_registers' attribute was previously declared without the 'no_caller_saved_registers' attribute}}

void __attribute__((no_caller_saved_registers)) foo6() {}
