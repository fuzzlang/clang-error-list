
// expected-error@-1 {{extraneous template parameter list in template specialization}}
//   expected-note@#cwg531-A-char {{'template<>' header not required for explicitly-specialized class 'cwg531::bad::A<char>' declared here}}
template<> struct A<char>::B {};
