
template<typename T> 
concept C1 = true; // expected-note{{previous}}

template<concept T> 
concept D1 = true; // expected-error{{expected template parameter}} // expected-error{{concept template parameter list must have at least one parameter; explicit specialization of concepts is not allowed}}
