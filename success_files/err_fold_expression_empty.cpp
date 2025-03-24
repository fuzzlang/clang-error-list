
template<int ...N> void bad_empty() {
    (N + ...); // expected-error {{empty expansion for operator '+' with no fallback}}
}

template void bad_empty<>(); // expected-note {{in instantiation of}}
