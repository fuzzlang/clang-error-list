
struct S {
    mutable constexpr int mi3 = 3; // expected-error {{'mutable' and 'const' cannot be mixed}} expected-error-re {{non-static data member cannot be constexpr{{$}}}}
};
