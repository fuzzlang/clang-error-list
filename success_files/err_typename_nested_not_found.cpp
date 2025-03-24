
namespace cwg399 {
  namespace QualifiedLookupInScope {
    namespace N {
      template <typename> struct S { struct Inner {}; };
    }
    template <typename U> void f(typename N::S<U>::Inner *p) {
      typedef typename N::S<U>::Inner T;
      p->::cwg399::QualifiedLookupInScope::N::S<U>::Inner::~T();  // expected-error{{no type named 'T' in 'cwg399::QualifiedLookupInScope::N::S<int>'}}
    }
    template void f<int>(N::S<int>::Inner *);
  }
}
