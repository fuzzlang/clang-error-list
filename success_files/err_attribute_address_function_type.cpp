
typedef void ft(void);

template <int I>
struct fooFunction {
    __attribute__((address_space(I))) ft qf; // expected-error {{function type may not be qualified with an address space}}
};
