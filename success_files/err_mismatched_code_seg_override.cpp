
// expected-error@38 {{derived class must specify the same code segment as its base classes}}
// expected-note@-2 {{in instantiation of template class}}
// expected-note@25 {{base class 'Base3' specified here}}

// Virtual overrides must have the same code_seg.
struct __declspec(code_seg("my_one")) Base3 {
  virtual int barA() { return 1; }
  virtual int __declspec(code_seg("my_two")) barB() { return 2; }
};
struct __declspec(code_seg("my_one")) Derived3 : Base3 {
  int barA() { return 4; } // ok
  int barB() { return 6; } // expected-error
};
