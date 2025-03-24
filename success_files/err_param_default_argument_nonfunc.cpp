
template<int f(int a = 0)> struct D; // expected-error {{default arguments can only be specified for parameters in a function declaration}}
