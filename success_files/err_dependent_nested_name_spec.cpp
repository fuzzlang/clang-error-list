
template<typename T> struct B {};

template<typename T> enum class B<T*>::E { e5, e6 }; // expected-error {{nested name specifier for a declaration cannot depend on a template parameter}}
