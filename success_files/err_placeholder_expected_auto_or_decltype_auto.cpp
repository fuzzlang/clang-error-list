
template<typename T>
concept C3 = requires(T t) { t + 1; };

C3 t1 = 0;  // expected-error {{expected 'auto' or 'decltype(auto)' after concept name}}
