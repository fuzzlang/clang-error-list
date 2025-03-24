
#if __cplusplus >= 201103L
namespace cwg2304 { // cwg2304: 2.8
template<typename T> void foo(T, int);
template<typename T> void foo(T&, ...);
struct Q; // #cwg2304-Q
void fn1(Q &data_vectors) {
  foo(data_vectors, 0); // expected-error {{missing argument for call to 'foo'}}
}
} // namespace cwg2304
#endif
