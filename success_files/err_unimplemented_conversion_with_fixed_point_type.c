
void func(void) {
    _Accum accum;
    double _Complex dc;
    
    accum = dc;      // expected-error{{conversion between fixed point and '_Complex double' is not yet supported}}
}
