
auto L13 = []() requires true {}; // expected-error{{non-templated function cannot have a requires clause}}
