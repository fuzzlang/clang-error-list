
template<int ...N>
int bad8() {
    return (N + ... * 3); // expected-error {{operators in fold expression must be the same}}
}
