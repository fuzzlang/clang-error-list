
template<class T> struct A {
  static T t; // expected-error{{static data member instantiated with function type 'int ()'}}
};

typedef int function();
A<function> a; // expected-note{{instantiation of}}
