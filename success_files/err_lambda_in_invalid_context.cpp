
template<typename T>
struct Nothing {};

void example() {
    Nothing<[]() { return 0; }()> nothing; // expected-error{{a lambda expression cannot appear in this context}}
}
