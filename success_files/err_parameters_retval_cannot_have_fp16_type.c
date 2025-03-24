
// expected-error@+2 {{function return value cannot have __fp16 type; did you forget * ?}}
__fp16 fp16_return(void) {
    return 0; // Error: Incorrect return type
}
