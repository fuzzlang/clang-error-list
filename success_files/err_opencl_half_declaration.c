
void kernel function_name() {
    half a[2]; // expected-error{{declaring variable of type '__private half[2]' is not allowed}}
}
