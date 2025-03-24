
class B {
protected:
    typedef int type; // #cwg402-B-type
};

class C {
    typedef int type; // #cwg402-C-type
    friend class A<C>; // #cwg402-friend-A-C
};

class D {
    typedef int type; // #cwg402-D-type
    friend class A<D, int>;
};

A<B> *b; // #cwg402-b
A<D> *d; // #cwg402-d

struct E {
    template<class T, class U = typename T::type> class A : public T {};
};

class F {
    typedef int type;
    friend class E;
};

E::A<F> eaf; // ok, default argument is in befriended context

template<class T, class U = typename T::type> void f(T) {} // #cwg402-f
