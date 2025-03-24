
void print();

template<typename T, int... Values>
void bogus_expansions(T x) {
    auto l2 = [Values...] {}; // expected-error{{'Values' in capture list does not name a variable}}
}
