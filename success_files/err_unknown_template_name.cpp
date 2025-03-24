
template<class T> struct imp;

template<class T> struct is_member_function_pointer : undeclared<imp<T>::member> {}; // expected-error {{unknown template name 'undeclared'}}
