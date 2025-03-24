
void to_foo5(int);
void to_foo5(int); // expected-note 3{{previous unmarked overload}}
void to_foo5(float) __attribute__((overloadable));
void to_foo5(double); // expected-error{{at most one overload for a given name may lack the 'overloadable' attribute}}
