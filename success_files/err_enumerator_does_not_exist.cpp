
struct Base {
    static const int a = 1;
};

template<typename T>
struct S : Base {
    enum E : int;
    constexpr int f() const;
    constexpr int g() const;
    void h();
};

template<> enum S<char>::E : int {}; // expected-note {{enum 'S<char>::E' was explicitly specialized here}}
template<> enum S<short>::E : int { b = 2 };
template<> enum S<int>::E : int { a = 4 };
template<typename T> enum S<T>::E : int { b = 8 };

template<typename T> constexpr int S<T>::f() const { return a; }
static_assert(S<char>().f() == 1, ""); 
static_assert(S<int>().f() == 1, ""); 

template<typename T> constexpr int S<T>::g() const { return b; } // expected-error {{enumerator 'b' does not exist in instantiation of 'S<char>'}}
static_assert(S<char>().g() == 1, ""); // expected-note {{here}} expected-error {{not an integral constant expression}}
static_assert(S<short>().g() == 2, ""); 
static_assert(S<long>().g() == 8, ""); 

template<typename T> void S<T>::h() {
    char c[S<T>::b];
    static_assert(b != 8, ""); 
    static_assert(sizeof(c) != 8, ""); 
}

void f() {
    S<short>().h(); // ok, b == 2
}
