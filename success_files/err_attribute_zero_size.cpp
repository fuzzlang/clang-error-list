
namespace Templates {
template <typename Elt, unsigned long long Size>
struct TemplateVectorType {
  typedef Elt __attribute__((__vector_size__(Size))) type; // expected-error {{zero vector size}}
};

void testZeroSize() {
  const TemplateVectorType<int, 0>::type ZeroSizeVector; // expected-note {{in instantiation of template class 'Templates::TemplateVectorType<int, 0>' requested here}}
}
}
