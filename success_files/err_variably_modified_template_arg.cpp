
template<typename T>
struct X0 {};

void inst_with_vla(int N) {
    int array[N]; // expected-warning{{variable length arrays in C++ are a Clang extension}}
    X0<__typeof__(array)> x0a; // expected-error{{variably modified type 'typeof (array)' (aka 'int[N]') cannot be used as a template argument}}
}
