
struct SealedType final {};

struct InheritFromSealed : SealedType {}; // expected-error{{base 'SealedType' is marked 'sealed'}}
