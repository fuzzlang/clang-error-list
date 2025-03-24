
template<typename T>
using A = int;

template<typename T>
using A<T*> = char; // expected-error {{partial specialization of alias templates is not permitted}}
