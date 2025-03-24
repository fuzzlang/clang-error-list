
namespace cwg1820 { // cwg1820: 3.5
typedef int A;
typedef int cwg1820::A; // expected-error@-2 {{typedef declarator cannot be qualified}}
void d1() {
  typedef int cwg1820::A; // expected-error@-2 {{typedef declarator cannot be qualified}}
}
} // namespace cwg1820
