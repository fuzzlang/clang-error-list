
decltype(auto) (*f2)(); // expected-error {{'decltype(auto)' can only be used as a return type in a function declaration}} 
// expected-error {{requires an initializer}}
