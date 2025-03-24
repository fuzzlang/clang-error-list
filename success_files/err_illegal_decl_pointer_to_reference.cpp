
namespace repro_illegal_decl_pointer_to_reference {

  struct Base {
    virtual void pure_virtual_function() = 0;
  };

  struct Abs : Base {
  }; // Expected-error here because Abs is an abstract class

  void func() {
    Abs a; // expected-error@-1 {{variable type 'Abs' is an abstract class}}
  }

  // Implementing the other part of the requirement which involves a misuse of pointer to reference
  template <typename T>
  void example(T t) {
    T &r = t;   // Valid reference
    T *p = &t;  // Valid pointer

    T &*ptr_to_ref = &r;  // expected-error{{pointer to reference is illegal}}
  }

}
