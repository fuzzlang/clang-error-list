
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=clc++ -fsyntax-only -verify

class virtual_functions {
  virtual void bad1() {}
};

class abstract_class {
  virtual void pure_virtual_function() = 0; // expected-error{{pure specifier requires 'override' or 'final' in the class definition}}
};

void some_function() {
  virtual_functions vf_instance;  // expected-error{{class 'virtual_functions' cannot be instantiated due to the presence of virtual function}}
  abstract_class ac_instance;      // expected-error{{cannot declare variable 'ac_instance' to be of abstract type 'abstract_class'}}
}
