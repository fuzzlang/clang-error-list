
// expected-error@+3 {{incorrect adjust_args type, expected 'need_device_ptr' or 'nothing'}}
#pragma omp declare variant(foo_v1)                        \
   match(construct={dispatch}, device={arch(arm)})         \
   adjust_args(badaaop AAA, BBB)

void foo_v1() {
    // Implementation of foo_v1
}
