
typedef int __attribute__((mode(SC))) __attribute__((vector_size(256))) vec_t10;
typedef _Complex float complex_vec_t __attribute__((vector_size(256))); // expected-error{{invalid vector element type '_Complex float'}}
