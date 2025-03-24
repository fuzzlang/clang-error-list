
__attribute__((regparm(-1))) int x2(void); // expected-error{{'regparm' parameter must be between 0 and 3 inclusive}}
