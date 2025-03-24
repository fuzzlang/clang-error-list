
template<typename T>
concept OneOf = requires(T x) { requires (sizeof(x) == sizeof(char) || sizeof(x) == sizeof(int)); };

template<OneOf auto &x> // expected-error {{constrained placeholder types other than simple 'auto' on non-type template parameters not supported yet}}
using K = int;
