
struct __attribute__((visibility("hidden"))) test4; // expected-error {{visibility does not match previous declaration}}
struct __attribute__((visibility("default"))) test4; // expected-error {{visibility does not match previous declaration}}
