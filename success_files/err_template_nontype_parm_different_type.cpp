
namespace test3 {
  template<typename T, T Value> struct X2a;

  template<typename T, int Size> struct X2b;

  template<typename T>
  class X3 {
    template<typename U, U Value> friend struct X2a;

    // expected-error {{template non-type parameter has a different type 'long' in template redeclaration}}
    template<typename U, T Value> friend struct X2b; 
  };

  X3<int> x3i; // okay
  X3<long> x3l; // expected-note {{in instantiation}}
}
