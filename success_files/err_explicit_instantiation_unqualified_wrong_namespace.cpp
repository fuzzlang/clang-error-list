
namespace M {
  template <class T> void f(T) {}
  namespace N {
    // expected-error@-1 {{cannot define or redeclare 'f' here because namespace 'M' does not enclose namespace 'N'}}
    template void f(long);
  }
}
