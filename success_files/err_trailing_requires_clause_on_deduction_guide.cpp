
template<typename T>
struct R { };

// expected-error{{deduction guide cannot have a requires clause}}
R(T) -> R<T> requires true;
