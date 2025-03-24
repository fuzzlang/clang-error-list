
#pragma OPENCL EXTENSION cl_khr_subgroups : enable

void test1(read_only pipe int p, global int* ptr) {
    int tmp;
    reserve_id_t rid;

    read_pipe(p, tmp, tmp, ptr);   // expected-error {{invalid argument type to function 'read_pipe' (expecting 'reserve_id_t' having '__private int')}}
}
