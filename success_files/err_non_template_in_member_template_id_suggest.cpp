
namespace InExpr {
    struct Base {
        template<typename T> static void foo(); // expected-note 4{{declared here}}
        int n;
    };

    struct Derived2 : Base {
        void goo(); // expected-note {{found}}
    };

    void testMember2() {
        Derived2().goo<int>(); // expected-error {{member 'goo' of 'InExpr::Derived2' is not a template; did you mean 'foo'?}}
    }
}
