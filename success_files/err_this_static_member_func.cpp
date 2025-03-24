
struct A {
    template<typename U>
    static auto h() -> decltype(this); // expected-error {{'this' cannot be used in a static member function declaration}}
};
