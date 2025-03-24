
template<typename T>
struct S {
    template<> friend void f<int>(int); // expected-error{{in a friend}}
};
