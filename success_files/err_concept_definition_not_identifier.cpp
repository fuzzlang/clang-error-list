
template <class T>
concept C7 = std::is_integral_v<T>;

template<> concept C7<int> = false; // expected-error{{concept template parameter list must have at least one parameter; explicit specialization of concepts is not allowed}}
