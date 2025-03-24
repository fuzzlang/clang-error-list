
namespace FunctionCast {
  typedef double (*DoubleFn)();
  int a[(int)DoubleFn(nullptr)()]; // expected-error {{variable length array}} expected-warning{{Clang extension}}
}
