
void f13(void) __attribute__((availability(shadermodel, introduced = 6.0, environment=pixel))); // expected-error {{unexpected parameter 'environment' in availability attribute, not permitted in C/C++}}

int main() {
    f13();
    return 0;
}
