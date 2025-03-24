
namespace ThisInLambdaWithCaptures {

struct Test {
    Test(auto&&);
};

void test() {
    int n = 12; // expected-error {{invalid use of member 'n' in explicit object member function}}
    int i = 100;
    
    [i = 0](this Test) { }(); // expected-error {{invalid use of 'this' in lambda}}
}
}
