
[[clang::always_destroy]] [[clang::no_destroy]] int p; // expected-error{{'no_destroy' and 'always_destroy' attributes are not compatible}} // expected-note{{here}}
