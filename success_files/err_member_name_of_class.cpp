
namespace cwg80 { // cwg80: 2.9
  struct A {
    int A;
  };
  struct B {
    static int B;
  };

  const int *ptr = nullptr; // expected-error@-1 {{default initialization of an object of const type 'const int'}}
  
  void func() {
    // OpenMP region
    #pragma omp parallel
    {
      // code block
    }
  }
}
