
class __attribute__((sycl_special_class)) class6 { // expected-error {{types with 'sycl_special_class' attribute must have one and only one '__init' method defined}}
  class6() {}
};
