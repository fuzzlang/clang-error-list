
int main() {
    #pragma clang unsafe_buffer_usage end    // expected-error{{not currently inside '#pragma unsafe_buffer_usage'}}
    return 0;
}
