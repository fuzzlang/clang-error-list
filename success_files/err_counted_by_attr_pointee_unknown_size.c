
#define __sized_by_or_null(f)  __attribute__((sized_by_or_null(f)))

struct on_member_pointer_fn_ty {
  int size;
  // expected-error@+1{{'sized_by_or_null' cannot be applied to a pointer with pointee of unknown size because 'void (void)' is a function type}}
  void (*fn_ptr)(void) __sized_by_or_null(size);
};
