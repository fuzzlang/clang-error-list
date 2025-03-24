
struct A {
    int a;
};

namespace NonPublicMembers {
    struct NonPublic1 {
    protected:
        int a; // expected-note {{declared protected here}}
    };

    struct NonPublic2 {
    private:
        int a; // expected-note 2{{declared private here}}
    };

    struct NonPublic3 : private A {}; // expected-note {{declared private here}}

    struct NonPublic4 : NonPublic2 {};
    
    void test() {
        auto [a3] = NonPublic3(); // expected-error {{cannot decompose members of inaccessible base class 'A' of 'NonPublicMembers::NonPublic3'}}
    }
}
