
template<typename ...T> struct X1t; // expected-note{{previous template type parameter pack declared here}}
template<typename T> struct X1t; // expected-error{{template type parameter conflicts with previous template type parameter pack}}
