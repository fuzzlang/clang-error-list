
struct T {
    template <typename T>
    void operator""_foo() {}
};

template<typename T>
void dependent_member_template() {
    T().template operator""_foo<int>(); // expected-error {{'operator""_foo' following the 'template' keyword cannot refer to a dependent template}}
}
