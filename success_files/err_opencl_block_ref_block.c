
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

typedef int (^bl2_t)(int);

kernel void f7(void) {
    bl2_t bl1 = ^(int i) {
        return 1;
    };
    void (^bl2)(void) = ^{
        int i = bl1(1); // expected-error {{cannot refer to a block inside block}}
    };
}
