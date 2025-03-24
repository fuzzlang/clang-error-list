
typedef __attribute__(( ext_vector_type(2) )) double double2;
typedef __attribute__(( ext_vector_type(4) )) double double4;

template<typename T, typename U, int N, int M>
struct ShuffleVector0 {
    void f(T t, U u, double2 a, double2 b) {
        (void)__builtin_shufflevector(t, u, N, M); // expected-error{{index}}
    }
};

template struct ShuffleVector0<double2, double2, 4, 3>; // expected-note{{instantiation}}
