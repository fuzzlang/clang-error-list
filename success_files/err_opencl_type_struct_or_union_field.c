
typedef struct {
    sampler_t smp; // expected-error{{the 'sampler_t' type cannot be used to declare a structure or union field}}
} MyStruct;

void myFunction() {
    MyStruct s;
}
