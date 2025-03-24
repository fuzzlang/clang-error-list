
#pragma OPENCL EXTENSION cl_khr_subgroups : enable

void test1(read_only pipe int p, global int* ptr) {
    write_pipe(p, ptr);    // expected-error {{invalid pipe access modifier (expecting write_only)}}
}
