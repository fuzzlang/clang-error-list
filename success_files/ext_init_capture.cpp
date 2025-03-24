
// expected-error@-2 {{initializer for variable 'x' with type 'auto' is empty}}
//   expected-note@#cwg1346-f {{in instantiation of function template specialization 'cwg1346::f<>' requested here}}
template<typename T>
void f();

template void f<int>(); // #cwg1346-f

#if __cplusplus >= 201103L
void init_capture() {
    [x(1)]{}(); // Here 'x' is declared but has no initializer, leading to the expected error.
}
#endif
