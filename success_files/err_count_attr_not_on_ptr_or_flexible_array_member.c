
#define __sized_by_or_null(f)  __attribute__((sized_by_or_null(f)))

struct on_pod_ty {
  int size;
  // expected-error-re@+1{{'sized_by_or_null' only applies to pointers{{$}}}}
  int wrong_ty __sized_by_or_null(size);
};
