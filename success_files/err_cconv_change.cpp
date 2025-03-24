
void free_func_default(); // expected-error {{function declared 'stdcall' here was previously declared without calling convention}}

void __stdcall free_func_default() {
    // function implementation
}
