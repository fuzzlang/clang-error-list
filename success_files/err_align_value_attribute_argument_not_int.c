
// expected-error@+1 {{'align_value' attribute requires integer constant}}
typedef double * __attribute__((align_value(4.5))) aligned_double4;
