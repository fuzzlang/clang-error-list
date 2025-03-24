
namespace templ {
    template<bool b>
    struct B {
        static constexpr bool value = b;
    };

    template<bool b>
    struct A {
        explicit(b) A(B<b>) {}
        template<typename T>
        explicit(b ^ T::value) operator T();
    };

    B<true> b_true;

    A a = { b_true }; // expected-error {{class template argument deduction}}
}
