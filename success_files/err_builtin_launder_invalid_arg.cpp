
namespace test_builtin_launder {
#define TEST_TYPE(Ptr, Type) \
  static_assert(__is_same(decltype(__builtin_launder(Ptr)), Type), "expected same type")

struct Dummy {};

using FnType = int(char);
using MemFnType = int (Dummy::*)(char);
using ConstMemFnType = int (Dummy::*)() const;

void foo() {}

void test_builtin_launder_diags(void *vp, const void *cvp, FnType *fnp,
                                MemFnType mfp, ConstMemFnType cmfp, int (&Arr)[5]) {
  __builtin_launder(vp);   // both-error {{void pointer argument to '__builtin_launder' is not allowed}}
  __builtin_launder(cvp);  // both-error {{void pointer argument to '__builtin_launder' is not allowed}}
}
}
