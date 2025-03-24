
#pragma clang attribute push (__attribute__((42))) // expected-error {{expected identifier that represents an attribute name}}

int main() {
    return 0;
}
