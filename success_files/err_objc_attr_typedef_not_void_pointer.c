
typedef struct Opaque *OpaqueRef __attribute__((objc_bridge(id))); // expected-error {{'objc_bridge(id)' is only allowed on structs and typedefs of void pointers}}
