
// RUN: %clang_cc1 -std=c++11 -verify=expected,cxx11 -fsyntax-only -pedantic-errors %s
// RUN: %clang_cc1 -std=c++14 -verify=expected,cxx14 -fsyntax-only -pedantic-errors %s -DCXX1Y

namespace n3323_example {

  template <class T> class zero_init {
  public:
    zero_init() : val(static_cast<T>(0)) {}
    zero_init(T val) : val(val) {}

    operator T &() { return val; }     //@13
    operator T() const { return val; } //@14

  private:
    T val;
  };

  void Delete() {
    zero_init<int *> p;
    p = new int(7);
    delete p; //@23
    delete (p + 0);
    delete + p;
  }

  void Switch() {
    zero_init<int> i;
    i = 7;
    switch (i) {} // @31
  }
  
  void SwitchError() {
    zero_init<int> j;
    j = 8;
    switch (j) { // This should trigger iserr_switch_multiple_conversions
      case 0: break;
      case 1: break;
    }
  }
}
