
template <typename T, typename T1> void foo(T t, T1 r) {
    T block_arg; 
    __block T1 byref_block_arg;

    T1 (^block)(T) = ^T1(T arg) { 
        byref_block_arg = arg;
        block_arg = arg;  // expected-error {{variable is not assignable (missing __block type specifier)}}
        return block_arg + arg; 
    };
}

int main(void) {
    foo(100, 'a'); 
}
