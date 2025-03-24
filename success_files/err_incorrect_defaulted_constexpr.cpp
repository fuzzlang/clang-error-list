
#if __cplusplus >= 201103L
namespace cwg1359 { // cwg1359: 3.5
  union A { constexpr A() = default; };
  union B { constexpr B() = default; int a; }; // expected-error@-1 {{defaulted definition of default constructor cannot be marked constexpr before C++23}} 
}
#endif
