
class TestBadPMF {
public:
    void func() {}
};

class Test {
public:
    using PMF = void (TestBadPMF::*)(); // Pointer to member function

    PMF pmf;

    [[clang::musttail]] TestBadPMF* operator->() {
        return nullptr; // Returning nullptr to reproduce the error
    }

    void example() {
        return ((*this)->*pmf)(); // expected-error {{left hand operand to ->* must be a pointer to class compatible with the right hand operand, but is 'TestBadPMF'}}
    }
};
