
// expected-error@-1 {{'template' keyword not permitted in destructor name}}
template<typename T> struct Y {};
template void test2(Y<int>*);
template void test2(ptr<Y<int> >);

void test3(int *p, ptr<int> q) {
    typedef int Int;
    p->~Int();
    q->~Int();
    p->Int::~Int();
    q->Int::~Int();
}

#if __cplusplus >= 201103L
template<typename T> using id = T;
struct A { template<typename T> using id = T; };
void test4(int *p, ptr<int> q) {
    p->~id<int>();
    q->~id<int>();
    p->id<int>::~id<int>();
    q->id<int>::~id<int>();
    p->template id<int>::~id<int>(); // OK since cwg2292
    q->template id<int>::~id<int>(); // OK since cwg2292
    p->A::template id<int>::~id<int>();
    q->A::template id<int>::~id<int>();
}
#endif

namespace cwg421 { // cwg421: yes
    struct X { X(); int n; int &r; };
    int *p = &X().n;
}
