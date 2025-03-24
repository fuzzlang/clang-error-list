
#define CONST const

class A {
  template<typename T> CONST T wrong;           // expected-error {{member 'wrong' declared as a template}}
  template<typename T> CONST T wrong_init = 5;  // expected-error {{member 'wrong_init' declared as a template}}
};
