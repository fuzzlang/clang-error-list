
struct Test {
    constexpr int mi1; // expected-error {{non-static data member cannot be constexpr; did you intend to make it const?}}
    static constexpr int mi2; // expected-error {{static member 'mi2' must have an initializer}}
};
