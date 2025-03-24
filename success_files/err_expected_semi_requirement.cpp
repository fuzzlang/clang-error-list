
using E = int;

template<typename T> requires requires { typename E<T>; } // expected-error{{expected ';' at end of requirement}}
struct r5v1 {};
