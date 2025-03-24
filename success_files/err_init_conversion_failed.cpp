
namespace cwg456 {
  const int null = 0;
  void *p = null; // expected-error {{cannot initialize a variable of type 'void *' with an lvalue of type 'const int'}}
}
