
namespace cwg176 {

template<typename T>
class Base {};

template<typename T>
class Derived1 : public Base<T> {};

template<typename T>
class Derived2 : public Base<T> {};

template<typename T>
class X {
  X *p1;
  X<T> *p2;
  X<int> *p3;
  cwg176::X *p4; // #cwg176-p4
};

template<>
class X<int> : public Derived1<int>, public Derived2<char> { // expected-error@-1 {{member 'Base' found in multiple base classes of different types}}
  typename Derived2::Base<double> d; // expected-note@#cwg176-Base {{member type 'cwg176::Base<int>' found by ambiguous name lookup}}
};

}
