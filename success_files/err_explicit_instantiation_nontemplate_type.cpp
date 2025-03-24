
struct X6 {
    struct Inner {};
};

template struct X6::Inner; // expected-error{{non-templated}}
