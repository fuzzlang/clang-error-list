
void __attribute__((regparm(2))) fc_f1(int i, int j, int k) {} // expected-error{{'regparm' is not valid on this platform}}
