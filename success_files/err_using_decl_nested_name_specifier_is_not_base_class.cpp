
namespace cwg1487 { // cwg1487: 3.3
#if __cplusplus >= 201103L
struct A { // #cwg1482-A
  struct B {
    using A::A; // since-cxx11-error@-1 {{using declaration refers into 'A::', which is not a base class of 'B'}}
  };
  
  // Other parts of the struct can remain empty to avoid additional errors
  struct C : A {
    using A::A; // since-cxx11-error@-1 {{using declaration refers into 'A::', which is not a base class of 'C'}}
  };
  
  struct D;
};
#endif
} // namespace cwg1487
