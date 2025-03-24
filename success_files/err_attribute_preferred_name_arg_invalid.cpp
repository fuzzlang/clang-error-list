
template<typename T> struct [[clang::preferred_name(int)]] B; // expected-error {{argument 'int' to 'preferred_name' attribute is not a typedef for a specialization of 'B'}}
