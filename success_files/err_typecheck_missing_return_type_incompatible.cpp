
auto lambda = []() { return ({ return 'c'; 1; }); }; // expected-error {{must match previous return type}}
