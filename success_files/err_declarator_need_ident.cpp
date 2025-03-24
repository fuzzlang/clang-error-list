
template<typename>
struct B;

template<typename>
using B_alias = B<int>;

template <>
B_alias() -> B<int>; // expected-error {{cannot specify deduction guide for alias template 'B'}}
