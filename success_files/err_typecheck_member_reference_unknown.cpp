
namespace FoundSingleTemplate {
    template<int I>
    struct A0;

    template<typename T>
    struct B {
        template<int I>
        void f1(); // expected-note 2{{possible target for call}}

        template<int I>
        struct A1; // expected-note 2{{member 'A1' declared here}}

        void g1() {
            this->A1<0; // expected-error {{expected '>'}}
            this->A1<0>; // expected-error {{cannot refer to member 'A1' in 'B<T>' with '->'}}
            this->A1<0>1; // expected-error {{cannot refer to member 'A1' in 'B<T>' with '->'}}
        }
    };
} // namespace FoundSingleTemplate
