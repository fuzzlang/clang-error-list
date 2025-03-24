
int main() {
#pragma clang unsafe_buffer_usage start // expected-error{{expected 'begin' or 'end'}}
    return 0;
}
