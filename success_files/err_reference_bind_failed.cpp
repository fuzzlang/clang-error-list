
namespace cwg2304 { // cwg2304: 2.8
template<typename T> void foo(T, int);
template<typename T> void foo(T&, ...);
struct Q; // forward declaration
void fn1(Q &data_vectors) {
  foo(data_vectors, 0); // expected-error@-1 {{argument type 'cwg2304::Q' is incomplete}} 
}
} // namespace cwg2304

namespace cwg2352 { // cwg2352: 10
int **p;
const int **const &f4() { return p; } // expected-error@-1 {{reference to type 'const int **const' could not bind to an lvalue of type 'int **'}}
}
