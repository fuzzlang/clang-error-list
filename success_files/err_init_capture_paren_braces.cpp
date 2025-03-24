
template <typename T>
void f() {
    // expected-error@-2 {{initializer for variable 'x' with type 'auto' is empty}}
    auto x = ;
    //   expected-note@#cwg1346-f {{in instantiation of function template specialization 'cwg1346::f<>' requested here}}
}

template void f(); // #cwg1346-f

#if __cplusplus >= 201103L
void init_capture() {
    [a(1)] {} ();
    // cxx11-error@-1 {{initialized lambda captures are a C++14 extension}}
    [b(1, 2)] {} ();
    // cxx11-error@-1 {{initialized lambda captures are a C++14 extension}}
    // since-cxx11-error@-2 {{initializer for lambda capture 'b' contains multiple expressions}}
    [c({})] {} ();
}
#endif
