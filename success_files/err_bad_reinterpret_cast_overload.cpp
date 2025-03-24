
namespace casting {
    using IntFooTy = void (*)(int *);

    void foo(int *c) __attribute__((enable_if(1, ""))); // Overloaded function prototypes
    void foo(char *c) __attribute__((enable_if(1, ""))); 

    void testIt() {
        auto A = reinterpret_cast<IntFooTy>(foo); // expected-error{{reinterpret_cast cannot resolve overloaded function 'foo' to type}}
        auto ARef = reinterpret_cast<IntFooTy>(&foo); // expected-error{{reinterpret_cast cannot resolve overloaded function 'foo' to type}}
    }
}
