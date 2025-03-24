
__attribute__((callback(cb))) void unknown_name1(void (*callback)(void)) {}  // expected-error {{'callback' attribute argument 'cb' is not a known function parameter}}
