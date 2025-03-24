
namespace extended_examples_array_bounds {

  typedef decltype(sizeof(int)) size_t;

  struct X {
    constexpr operator size_t() const { return 1; } // cxx11-note 3{{conversion}}
    constexpr operator unsigned short() const { return 0; } // cxx11-note 3{{conversion}}
  };

  void f() {
    X x;
    int *p = new int[x]; // expected-error {{ambiguous}}
    
    int arr[x]; // expected-error {{ambiguous}}
  }
}
