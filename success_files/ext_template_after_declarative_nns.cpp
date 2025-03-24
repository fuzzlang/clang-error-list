
template<typename T> struct A {
    template<typename U> struct B {
        struct C;
        template<typename V> struct D;

        void f();
        template<typename V> void g();

        static int x;
        template<typename V> static int y;

        enum class E;
    };
};

template<typename T>
template<typename U>
struct A<T>::template B<U>::C { }; // expected-error{{'template' cannot be used after a declarative}}
