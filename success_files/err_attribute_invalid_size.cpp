
typedef int invalid_vector_type __attribute__((__vector_size__(5)));  // expected-error {{invalid vector element type 'int'}}

namespace LLVMTesting {
template <typename ElementType, unsigned long long InvalidSize>
struct TestVector {
  typedef ElementType __attribute__((__vector_size__(InvalidSize))) vector_type; // #1
};

template <int M, typename El>
struct TestPR15730 {
  typedef El __attribute__((__vector_size__(M * sizeof(El)))) test_type;
  typedef El __attribute__((__vector_size__(0xFFFFFFFFFF))) test_type2; // #2
  typedef El __attribute__((__vector_size__(7))) test_type3; // #3
};
}
