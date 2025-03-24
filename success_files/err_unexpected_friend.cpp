
namespace cwg585 { // cwg585: 3.0
  template<typename> struct T; // #cwg585-struct-T
  struct A {
    friend T; // expected-error@-1 {{ordered comparison between pointer and zero ('int *' and 'int')}}
  };
}
