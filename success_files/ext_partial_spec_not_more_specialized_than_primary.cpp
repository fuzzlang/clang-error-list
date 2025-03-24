
namespace cwg1495 { // cwg1495: 4
#if __cplusplus >= 201103L
  template<typename T, typename U> struct A {}; // #cwg1495-A
  template<typename T, typename U> struct A<U, T> {}; // since-cxx11-error@-1 {{class template partial specialization is not more specialized than the primary template}}
#endif
} // namespace cwg1495
