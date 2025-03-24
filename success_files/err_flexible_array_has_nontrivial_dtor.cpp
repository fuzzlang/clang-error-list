
struct NonTrivDtor {
    ~NonTrivDtor() {}
};

struct Container {
    NonTrivDtor ntd[]; // expected-error {{flexible array member 'ntd' of type 'NonTrivDtor[]' with non-trivial destruction}}
};
