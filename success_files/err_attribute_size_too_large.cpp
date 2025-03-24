
namespace Templates {
template <typename Elt, unsigned long long Size>
struct TemplateVectorType {
  typedef Elt __attribute__((__vector_size__(68719476736))) type; // expected-error {{vector size too large}}
};

void Init() {
  const TemplateVectorType<int, 68719476736>::type TooLarge = {}; // triggers the expected error
}
} // namespace Templates
