
template<int> int missing_args; // expected-note {{here}}
template int missing_args; // expected-error {{must specify a template argument list}}
