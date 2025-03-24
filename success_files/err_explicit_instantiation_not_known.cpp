
namespace M {
    template <class T> void g(T) {}
    template <> void g(char) {}

    template void f(long); // expected-error@-1 {{cannot define or redeclare 'f' here because namespace 'M' does not enclose namespace 'N'}}
    
    template void N::f(unsigned long); // since-cxx11-error@-1 {{explicit instantiation of 'cwg275::N::f' must occur in namespace 'N'}}
    
    template void h(long); // since-cxx11-error@-1 {{explicit instantiation of 'f' not in a namespace enclosing 'N'}}
}
