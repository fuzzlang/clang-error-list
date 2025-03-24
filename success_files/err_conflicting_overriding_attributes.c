
void preserves_za_fn_ptr(void) {
  // expected-error@+2 {{call to a shared ZA function requires the caller to have ZA state}}
}

void shared_za_definition(void (*shared_za_fn_ptr)(void) __arm_inout("za")) __arm_inout("za") {
  preserves_za_fn_ptr(); // OK
  shared_za_fn_ptr(); // OK
}

__arm_new("za") void new_za_definition(void (*shared_za_fn_ptr)(void) __arm_inout("za")) {
  preserves_za_fn_ptr(); // OK
  shared_za_fn_ptr(); // OK
}

#ifdef __cplusplus
int shared_za_initializer(void) __arm_inout("za");
// expected-cpp-error@+1 {{call to a shared ZA function requires the caller to have ZA state}}
int global = shared_za_initializer();

struct S {
  virtual void shared_za_memberfn(void) __arm_inout("za");
};

struct S2 : public S {
  // expected-cpp-error@+2 {{virtual function 'shared_za_memberfn' has different attributes ('void ()') than the function it overrides (which has 'void () __arm_inout("za")')}}
  // expected-cpp-note@-5 {{overridden virtual function is here}}
  __arm_new("za") void shared_za_memberfn(void) override {} 
};
