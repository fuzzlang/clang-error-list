
template <typename Name, typename Func>
__attribute__((sycl_kernel)) void kernel(const Func &kernelFunc) {
  kernelFunc(); // #KernelObjCall
}

typedef float ZEROARR[0];

struct Wrapper {
  int A;
  int BadArray[0]; // expected-note 3{{field of illegal type 'int[0]' declared here}}
};

struct WrapperOfWrapper { // expected-error 2{{zero-length arrays are not permitted in SYCL device code}}
  Wrapper F;              // expected-note 2{{within field of type 'Wrapper' declared here}}
  ZEROARR *Ptr;          //expected-note 5{{field of illegal pointer type 'ZEROARR *' (aka 'float (*)[0]') declared here}}
};

void foo(const unsigned X) {
  int Arr[0];      // expected-note 2{{declared here}}
  ZEROARR TypeDef; // expected-note {{declared here}}
  ZEROARR *Ptr;    // expected-note {{declared here}}
  
  kernel<class Simple>([=]() { 
    (void)Arr;     // expected-error {{zero-length arrays are not permitted in SYCL device code}}
    (void)TypeDef; // expected-error {{zero-length arrays are not permitted in SYCL device code}}
    (void)Ptr;     // expected-error {{zero-length arrays are not permitted in SYCL device code}}
  });
}
