
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -pedantic -verify -fsyntax-only

// This test checks that various C/C++/OpenCL C constructs are not available in
// C++ for OpenCL.

// Test that typeid is not available.
namespace std {
  // Provide a dummy std::type_info so that we can use typeid.
  class type_info {
    int a;
  };
}

_kernel void test_kernel() {
  __constant std::type_info int_ti = typeid(int);
}
