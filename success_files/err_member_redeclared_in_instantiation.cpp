
namespace injected_class_name {
  template<typename T> struct A {
    A(T);
    void f(int) { // expected-note {{previous}}
      A a = 1;
      injected_class_name::A b = 1; // expected-note {{in instantiation of template class 'injected_class_name::A<int>'}}
    }
    void f(T); // expected-error {{multiple overloads of 'f' instantiate to the same signature 'void (int)'}}
  };
  A<short> ai = 1;
}
