
struct Vector {
    __vector float xyzw;
} __attribute__((vecreturn)) __attribute__((vecreturn));  // expected-error {{'vecreturn' attribute cannot be repeated}}
