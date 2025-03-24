
// expected-error@-1 {{reference to 'U' is ambiguous}}
//   expected-note@#cwg14-X-U {{candidate found by name lookup is 'cwg14::X::U'}}
//   expected-note@#cwg14-Y-U {{candidate found by name lookup is 'cwg14::Y::U'}}
}

namespace cwg14 {
  struct X {
    using U = int;
  };
  
  struct Y {
    using U = float;
  };
  
  template<typename T> void f(int);
  template<typename T> void f(int = 0);
}
