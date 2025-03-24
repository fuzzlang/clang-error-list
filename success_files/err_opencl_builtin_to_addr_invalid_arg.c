
// expected-error@-4{{too many arguments to function call, expected 1, have 2}}
#define __OPENCL_C_VERSION__ 220
__kernel void test_kernel() {
  int x;
  glob = to_global(x); // This line triggers the expected error
}
