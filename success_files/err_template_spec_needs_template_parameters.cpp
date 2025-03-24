
namespace PR10109 {
template<typename T>
struct A {
protected:
  struct B;
  struct B::C; // expected-error{{requires a template parameter list}}
};
} // namespace PR10109
