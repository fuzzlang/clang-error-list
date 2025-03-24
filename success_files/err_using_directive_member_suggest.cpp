
namespace blargh {
    void foo() {}
}

void test() {
    using namespace ::blarg; // expected-error{{no namespace named 'blarg' in the global namespace; did you mean 'blargh'?}}
}
