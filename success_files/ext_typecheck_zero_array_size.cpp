
template<int N>
struct Z {
    constexpr operator int() const { return N; }
};

void h() {
    int arrA[Z<1>()];
    int arrB[Z<0>()]; // expected-error {{zero size array}}
    int arrC[Z<-1>()]; // expected-error {{'arrC' declared as an array with a negative size}}
}
