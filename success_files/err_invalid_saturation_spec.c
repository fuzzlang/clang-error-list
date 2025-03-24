
void test() {
    _Sat float f; // expected-error{{'_Sat' specifier is only valid on '_Fract' or '_Accum', not 'float'}}
}
