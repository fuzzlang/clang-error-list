
struct NonPublicMembers {
    struct NonPublic1 {
    protected:
        int a; // expected-note {{declared protected here}}
    };

    void test() {
        auto [a1] = NonPublic1(); // expected-error {{cannot decompose protected member 'a' of 'NonPublicMembers::NonPublic1'}}
    }
};
