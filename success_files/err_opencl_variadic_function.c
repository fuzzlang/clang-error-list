
// RUN: %clang_cc1 %s -cl-std=CL1.0 -verify -pedantic -fsyntax-only -triple spir-unknown-unknown
// RUN: %clang_cc1 %s -cl-std=CL1.0 -verify -pedantic -fsyntax-only -triple spir-unknown-unknown -DFUNCPTREXT
// RUN: %clang_cc1 %s -cl-std=CL1.0 -verify -pedantic -fsyntax-only -triple spir-unknown-unknown -DVARARGEXT

#ifdef FUNCPTREXT
#pragma OPENCL EXTENSION __cl_clang_function_pointers : enable
#endif
#ifdef VARARGEXT
#pragma OPENCL EXTENSION __cl_clang_variadic_functions : enable
#endif

// Variadic functions 
void vararg_f(int, ...); 

__kernel void test_kernel() {
    vararg_f(1, 2.0f); // Expected to trigger the iserr_opencl_variadic_function error
}
