
template<typename T, int N, template<typename X> class TT>
struct Test0; // expected-error{{does not specialize}}

template<typename T, int N, template<typename X> class TT>
struct Test0<T, N, TT> { }; // This line provides the specialization for the error check in the previous line.

int main() {
    return 0;
}
