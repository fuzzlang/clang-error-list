
#define UIE __attribute__((using_if_exists))

namespace test_redecl {
    namespace NS {}

    using NS::x UIE; // expected-error{{'using_if_exists' attribute cannot be applied to an inheriting constructor}}
    struct BaseCtor {};
    
    template <class Base>
    struct UseCtor : Base {
        using Base::Base UIE; // expected-error{{'using_if_exists' attribute cannot be applied to an inheriting constructor}}
    };
    
    void f() {
        UseCtor<BaseCtor> usector;
    }
} // namespace test_redecl
