
namespace N {
    template <class T> 
    void f(T) {}
}

namespace M {
    // The following explicit instantiation causes an error because it's not in namespace N
    template void N::f(unsigned long); // expected-error{{explicit instantiation of 'f' not in a namespace enclosing 'N'}}
}
