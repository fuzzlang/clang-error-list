
void operator_parens() {
  [&](int x){ operator()(); }(0); // expected-error {{undeclared 'operator()'}}
}
