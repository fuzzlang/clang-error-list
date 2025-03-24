
#pragma clang unsafe_buffer_usage begin  // expected-error{{'#pragma unsafe_buffer_usage' was not ended}}

int main() {
    int a = 0;
    int *b = &a;
    
    // Some operations
    a = *b + 1;

    return 0;
}
