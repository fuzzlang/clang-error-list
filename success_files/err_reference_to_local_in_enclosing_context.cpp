
namespace temp_func_order_example3 {
    template <typename T, typename... U> void f(T, U...);
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template <typename T> void f(T);
    template <typename T, typename... U> int &g(T *, U...);
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template <typename T> void g(T);
    void h(int i) {
        // This is made ambiguous by cwg692, but made valid again by cwg1395.
        f(&i);
        int &r = g(&i); // expected-error@-1 {{ambiguous}}
    }
}

namespace temp_deduct_partial_example {
    template <typename... Args> char &f(Args... args);
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template <typename T1, typename... Args> short &f(T1 a1, Args... args);
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template <typename T1, typename T2> int &f(T1 a1, T2 a2);
    void g() {
        char &a = f(); // expected-error@-1 {{ambiguous}}
        short &b = f(1, 2, 3); // expected-error@-1 {{ambiguous}}
        int &c = f(1, 2); // expected-error@-1 {{ambiguous}}
    }
}

namespace temp_deduct_type_example1 {
    template <class T1, class ...Z> class S;
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template <class T1, class ...Z> class S<T1, const Z&...>;
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template <class T1, class T2> class S<T1, const T2&> {};
    S<int, const int&> s;

    template<class T, class... U> struct A;
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template<class T1, class T2, class... U> struct A<T1,T2*,U...> {};
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template<class T1, class T2> struct A<T1,T2>;
    template struct A<int, int*>;
}

namespace temp_deduct_type_example3 {
    template<class T, class... U> void f(T*, U...){}
    // cxx98-error@-1 {{variadic templates are a C++11 extension}}
    template<class T> void f(T){}
    template void f(int*);
}

namespace cwg696 { // cwg696: 3.1
    void f(const int*);
    void g() {
        const int N = 10; // #cwg696-N
        struct A {
            void h() {
                int arr[N]; (void)arr;
                f(&N); // expected-error@-1 {{ambiguous}}
            }
        };
    }
}
