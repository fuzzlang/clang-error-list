
namespace cwg180 { // cwg180: 2.8
  template<typename T> struct X : T, T::some_base {
    X() : T::some_type_that_might_be_T(), T::some_base() {}
    friend class T::some_class;
    void f() {
      enum T::some_enum e; // expected-error@-1 {{arithmetic on pointers to the function type 'void ()'}}
      T::some_function_ptr ptr;
      ptr++; // Intentional arithmetic operation on a function pointer
    }
  };
}

namespace cwg181 { // cwg181: yes
  namespace X {
    template <template X<class T> > struct A { };
  }
}
