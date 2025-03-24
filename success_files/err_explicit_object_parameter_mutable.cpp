
auto l2 = [] (this auto) mutable {}; // expected-error{{a lambda with an explicit object parameter cannot be mutable}}
