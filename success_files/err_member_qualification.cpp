
namespace cwg1820 {
class C1 {
  typedef int cwg1820::A; // expected-error {{typedef declarator cannot be qualified}}
};
} // namespace cwg1820
