
struct Incomplete;

int main() {
    auto l1 = [] () -> Incomplete { }; // expected-error{{incomplete result type 'Incomplete' in lambda expression}}
    return 0;
}
