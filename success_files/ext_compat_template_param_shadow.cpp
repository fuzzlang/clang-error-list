
template<typename T> struct B {};

template<typename T> B<T*>(T*) -> B<T*>; // expected-error {{}} expected-note {{}} 
