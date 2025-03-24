
namespace cwg448 { // cwg448: 2.8
  template<typename T = int> void f(int); // #cwg448-f-int
  // cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
  
  template<typename T> void g(T t) {
    f<T>(t); // expected-error@-1 {{call to function 'f' that is neither visible in the template definition nor found by argument-dependent lookup}}
  }
  
  template<typename T> void f(T); // #cwg448-f-T

  namespace HideFromADL { struct X {}; }
  template void g(HideFromADL::X); // #cwg448-g
}
