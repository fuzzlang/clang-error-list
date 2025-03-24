
void might_crash();

void use_seh_after_cxx() {
    try { // expected-note {{conflicting 'try' here}}
        might_crash();
    } catch (int) {
    }
    __try { // expected-error {{cannot use C++ 'try' in the same function as SEH '__try'}}
        might_crash();
    } __except(1) {
    }
}
