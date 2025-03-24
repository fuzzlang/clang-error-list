
void exampleFunction() {
    #pragma clang unsafe_buffer_usage begin
    #pragma clang unsafe_buffer_usage begin  // expected-error{{already inside '#pragma unsafe_buffer_usage'}}
}
