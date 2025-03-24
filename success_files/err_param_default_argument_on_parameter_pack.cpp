
template<typename... Ts>
void defaultpack(Ts... = 0) {} // expected-error{{parameter pack cannot have a default argument}}
