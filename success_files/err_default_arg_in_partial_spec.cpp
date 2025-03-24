
template<typename T = int> class C; // OK: primary template with default argument

template<typename T = float> class C<T*> {}; // expected-error{{default template argument}}
