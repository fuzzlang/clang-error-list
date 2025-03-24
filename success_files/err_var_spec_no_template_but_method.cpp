
template<typename T>
int f();

template<> 
int f<double>; // expected-error {{no variable template matches specialization; did you mean to use 'f' as function template instead?}}
