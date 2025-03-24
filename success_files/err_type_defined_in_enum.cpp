
enum PR28903 {
    PR28903_A = (enum { // expected-error-re {{'PR28903::(unnamed enum at {{.*}})' cannot be defined in an enumeration}}
        PR28903_B,
        PR28903_C
    })
};
