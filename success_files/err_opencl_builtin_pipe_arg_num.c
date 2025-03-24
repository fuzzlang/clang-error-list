
#pragma OPENCL EXTENSION cl_khr_subgroups : enable

void test1(read_only pipe int p, global int* ptr) {
    int tmp;
    reserve_id_t rid;

    read_pipe(p);   // expected-error {{invalid number of arguments to function: 'read_pipe'}}
}
