
struct __multiple_inheritance A {};

// expected-error@#1 {{inheritance model does not match definition}}
struct __multiple_inheritance B : A {};
