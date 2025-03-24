
template<typename T>
struct WBase {};

template<typename T>
struct W : WBase<T> {
    typedef int X;
    int n;
};

void w_test() {
    typename W<int>::W w2a; // expected-error@-1 {{qualified reference to 'W' is a constructor name rather than a type in this context, despite preceding 'typename' keyword}}
}
