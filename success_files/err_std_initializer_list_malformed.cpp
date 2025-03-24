
// RUN: %clang_cc1 -std=c++11 -verify=cxx11 -emit-llvm-only %s
// RUN: %clang_cc1 -std=c++98 -fsyntax-only -verify=cxx98 %s
// RUN: %clang_cc1 -std=c++11 -verify=cxx11 -emit-llvm-only %s -fexperimental-new-constant-interpreter
// RUN: %clang_cc1 -std=c++98 -fsyntax-only -verify=cxx98 %s -fexperimental-new-constant-interpreter

namespace std {
  template <class _E>
  class initializer_list {};
}

void test_function() {
    std::initializer_list<int> il = {1, 2, 3}; // error: no match for ‘initializer_list’ 
}
