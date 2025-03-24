
struct T {
    template<typename T>
    static void operator""_q();
};

void test() {
    T::template operator""_q<'a'>(); // expected-error {{non-namespace scope 'T::' cannot have a literal operator member}} expected-error +{{}}
}
