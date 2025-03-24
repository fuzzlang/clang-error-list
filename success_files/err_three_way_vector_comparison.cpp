
namespace Vector {
  typedef __attribute__((ext_vector_type(4))) int V;
  void f(V v1, V v2) {
    (void)(v1 <=> v2); // expected-error {{three-way comparison between vectors is not supported}}
  }
}
