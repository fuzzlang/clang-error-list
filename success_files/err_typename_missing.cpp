
namespace cwg666 { // cwg666: 2.8
  struct P { friend P operator*(P, P); P(int); } p(0);

  template<int> int f();
  template<typename T> int f() {
    T::type *p = 0; // expected-error@-1 {{missing 'typename' prior to dependent type name 'Y::type'}}
    return 0;
  }
  struct X { static const int type = 0; };
  struct Y { typedef int type; };
  int a = f<X>();
  int b = f<Y>(); // #cwg666-f-Y
}
