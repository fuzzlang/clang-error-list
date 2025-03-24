
// RUN: %clang_cc1 -fsyntax-only -verify=expected,spec %s
// RUN: %clang_cc1 -fsyntax-only -verify -Wno-explicit-specialization-storage-class %s

template<typename T> void f(T) {}
template<typename T> static void g(T) {}

template static void f<float>(float); // expected-error{{explicit instantiation cannot have a storage class}}
