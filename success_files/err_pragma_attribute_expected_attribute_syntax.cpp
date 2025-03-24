
#pragma clang attribute push (42) // expected-error {{expected an attribute that is specified using the GNU, C++11 or '__declspec' syntax}}

int main() {
    return 0;
}
