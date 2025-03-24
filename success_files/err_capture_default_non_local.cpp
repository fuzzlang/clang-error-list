
auto y = [&]{ struct S { int n, m = n; }; }; // expected-error {{non-local lambda expression cannot have a capture-default}}
