
template<int T>
concept IsEven = (T % 2) == 0;

template<typename T> 
requires requires (T t) { { t } -> IsEven; } // expected-error{{concept named in type constraint is not a type concept}}
struct r11 {};
