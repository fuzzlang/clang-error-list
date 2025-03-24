
template <typename T>
void test() {
    typename T::template operator""_q<'a'> a; // expected-error {{non-namespace scope 'T::' cannot have a literal operator member}} expected-error +{{}}
}

int main() {
    return 0;
}
