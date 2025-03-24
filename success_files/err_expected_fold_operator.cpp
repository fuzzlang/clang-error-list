
template<int ...N>
int bad11() {
    return (N + ... 0); // expected-error {{expected a foldable binary operator}} expected-error {{expected expression}}
}
