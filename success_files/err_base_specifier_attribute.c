
struct A {};

struct B : __arm_inout("za") A {}; // expected-error {{'__arm_inout' cannot be applied to a base specifier}}
