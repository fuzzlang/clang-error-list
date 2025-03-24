
namespace ns5 {
template < typename T> T* foo (T);
template <> int* foo(int); // expected-note{{previous}}
template <> int* foo(int) = delete; // expected-error{{deleted definition must be first declaration}}
} // end ns5
