
// expected-error@-2 {{type 'float' cannot be used prior to '::' because it has no members}}
//   expected-note@#cwg727-N-float {{in instantiation of static data member 'cwg727::D<int>::N<float>' requested here}}

template<> struct C<int> {};
template<> void f<int>() {}
template<> const int N<int>;

template<typename T> struct C<T*> {};
template<typename T> static const int N<T*>;

template<typename>
struct E {
  template<> void f<void>() {}
};

template<> struct C<float> {}; // This instantiation should trigger the expected error
