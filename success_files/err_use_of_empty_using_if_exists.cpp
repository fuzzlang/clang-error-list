
#define UIE __attribute__((using_if_exists))

namespace test_basic {
    namespace NS {}

    using NS::x UIE; // expected-note{{using declaration annotated with 'using_if_exists' here}}
    x usex();        // expected-error{{reference to unresolved using declaration}}
}
