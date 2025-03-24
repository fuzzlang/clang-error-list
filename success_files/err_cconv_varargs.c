
void __attribute__((thiscall)) test4(int a, ...) { 
    // expected-error {{variadic function cannot use thiscall calling convention}}
}
