
template <int N>
struct D {
    ~D() requires(N != 0) = delete; // expected-note {{explicitly marked deleted}}
    ~D() requires(N == 1) = delete;  // expected-note {{explicitly marked deleted}}
};

template struct D<1>; // expected-error {{destructor of class 'D<1>' is ambiguous}} expected-note {{in instantiation of template}}
