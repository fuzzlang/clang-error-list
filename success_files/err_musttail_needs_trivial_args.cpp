
struct HasNonTrivialDestructor {
public:
    ~HasNonTrivialDestructor() {}
};

int NonTrivialParam(HasNonTrivialDestructor x);

int TestNonTrivialParam(HasNonTrivialDestructor x) {
    [[clang::musttail]] return NonTrivialParam(x); // expected-error {{tail call requires that the return value, all parameters, and any temporaries created by the expression are trivially destructible}}
}
