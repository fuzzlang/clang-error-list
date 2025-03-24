
typedef void **omp_allocator_handle_t;
extern const omp_allocator_handle_t omp_null_allocator;
extern const omp_allocator_handle_t omp_default_mem_alloc;
extern const omp_allocator_handle_t omp_large_cap_mem_alloc;
extern const omp_allocator_handle_t omp_const_mem_alloc;
extern const omp_allocator_handle_t omp_high_bw_mem_alloc;
extern const omp_allocator_handle_t omp_low_lat_mem_alloc;
extern const omp_allocator_handle_t omp_cgroup_mem_alloc;
extern const omp_allocator_handle_t omp_pteam_mem_alloc;
extern const omp_allocator_handle_t omp_thread_mem_alloc;

void xxx(int argc) {
  int fp; // expected-note {{initialize the variable 'fp' to silence this warning}}
#pragma omp target simd reduction(+:fp) // expected-warning {{variable 'fp' is uninitialized when used here}}
  for (int i = 0; i < 10; ++i)
    ;
}

void foo() {
}

bool foobool(int argc) {
  return argc;
}

void foobar(int &ref) {
#pragma omp target simd reduction(+:ref) allocate(omp_thread_mem_alloc: ref) uses_allocators(omp_thread_mem_alloc) // expected-error {{unexpected OpenMP clause 'uses_allocators' in directive '#pragma omp target simd'}}
}
