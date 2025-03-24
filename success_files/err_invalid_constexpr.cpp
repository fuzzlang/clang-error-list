
auto XL3 = [](constexpr mutable constexpr { // expected-error{{invalid storage class specifier}} 
    return 42;
};
