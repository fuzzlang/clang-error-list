
typedef _BitInt(2) __attribute__((vector_size(16))) VecTy; // expected-error{{'_BitInt' vector element width must be at least as wide as 'CHAR_BIT'}}
