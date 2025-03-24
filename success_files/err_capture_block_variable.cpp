
void test() {
    __block int e = 10; // expect error here
    
    auto lambda = [&]() { return e; }; // expected-error {{__block variable 'e' cannot be captured in a lambda expression}}
}
