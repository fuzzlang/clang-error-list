
typedef __attribute__((__clang_arm_mve_strict_polymorphism)) int i; // expected-error {{'__clang_arm_mve_strict_polymorphism' attribute can only be applied to an MVE/NEON vector type}}
