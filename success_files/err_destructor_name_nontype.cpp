
template<typename B> struct CtorDtorName : B {
  using B::CtorDtorName; // expected-error {{member 'CtorDtorName' has the same name as its class}} expected-note {{non-type declaration found by destructor name lookup}}
  CtorDtorName();
  ~CtorDtorName(); // expected-error {{identifier 'CtorDtorName' after '~' in destructor name does not name a type}}
};
