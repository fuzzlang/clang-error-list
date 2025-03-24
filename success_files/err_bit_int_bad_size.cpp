
struct S {
    _BitInt(0) h; // expected-error{{signed _BitInt must have a bit size of at least 2}}
};
