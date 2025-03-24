
int main() {
    long double x = 1.0; // expected-error@+2{{'x' requires  'long_double' (aka 'long double') type support, but target 'i686-unknown-linux-gnu' does not support it}}
    return (int)x;
}
