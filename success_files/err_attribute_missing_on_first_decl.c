
int var4 __attribute__((common)); // expected-note{{previous declaration is here}} expected-note{{conflicting attribute is here}}
int var4 __attribute__((internal_linkage)); // expected-error{{'internal_linkage' and 'common' attributes are not compatible}} 
// expected-error{{'internal_linkage' attribute does not appear on the first declaration}}
