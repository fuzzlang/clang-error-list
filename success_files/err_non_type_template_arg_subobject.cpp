
namespace cwg1802 { // cwg1802: Example case
struct B { union { int m; }; };
static_assert(__is_same(__decltype(&B::m), int B::*), "");
} // namespace cwg1802

namespace cwg1803 { // cwg1803: Another example
static union {
  int j;
};

template <int &> struct T {}; // #cwg1803-T
T<j> W; // #cwg1803-T-j
