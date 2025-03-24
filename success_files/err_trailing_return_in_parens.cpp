
template<typename> struct A {};

(A(int(&)[10]) -> A<int>); // expected-error {{trailing return type may not be nested within parentheses}}
