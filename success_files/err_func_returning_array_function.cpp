
namespace error_example {
#if __cplusplus >= 201103L
    using T = int[3];
    int &&r = T{}[1]; // expected-error {{cannot return a function that returns an array}}

    using T = decltype((T{}));
    using U = decltype((T{}[2]));
    using U = int &&;

    struct ConvertsToInt {
        operator int();
    };
    struct X { int array[1]; };
    using U = decltype(X().array[ConvertsToInt()]);

    typedef int V4Int __attribute__((__vector_size__(sizeof(int) * 4)));
    typedef int EV4Int __attribute__((__ext_vector_type__(4)));
    using U = decltype(V4Int()[0]);
    using U = decltype(EV4Int()[0]);
#endif
}

#if __cplusplus >= 201103L
namespace function_example {
    struct M;
    template <typename T>
    struct V;
    struct S {
        S* operator()();
        int N;
        int M;
#if __cplusplus >= 202302L
        template <typename T>
        static constexpr auto V = 0;
        void f(char);
        void f(int);
        void mem(S s) {
            auto(s)()->M; // expected-error {{cannot return a function that returns an array}}
        }
#endif
    };

    void f(S s) {
        {
#if __cplusplus >= 202302L
            auto(s)()->N; // expected-error {{cannot return a function that returns an array}}
#endif
            auto(s)()->M; // expected-error {{cannot return a function that returns an array}}
        }
        {
            S(s)()->N; // expected-error {{cannot return a function that returns an array}}
            S(s)()->M; // expected-error {{cannot return a function that returns an array}}
        }
    }

    struct A {
        A(int*);
        A *operator()();
    };
    typedef struct BB { int C[2]; } *B, C;
    void g() {
        A a(B ()->C); // expected-error {{cannot return a function that returns an array}}
        A b(auto ()->C); // expected-error {{cannot return a function that returns an array}}
        static_assert(sizeof(B ()->C[1] == sizeof(int)), "");
        sizeof(auto () -> C[1]); // expected-error {{cannot return a function that returns an array}}
    }
#endif
}
