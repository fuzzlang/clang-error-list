
namespace cwg1837 { // cwg1837: 3.3
#if __cplusplus >= 201103L
  template <typename T>
  struct Fish { static const bool value = true; };

  struct Other {
    int p();
    auto q() -> decltype(p()) *;
  };

  class Outer {
    friend auto Other::q() -> decltype(this->p()) *; // expected-error@-1 {{unknown type name 'E3'}}
  };
#endif
} // namespace cwg1837
