
struct omp_alloctrait_t {};
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

int main(int argc, char **argv) {
    omp_alloctrait_t traits[10];
    omp_alloctrait_t *ptraits;
    omp_allocator_handle_t my_alloc = nullptr;
    const omp_allocator_handle_t c_my_alloc = my_alloc;

    #pragma omp target uses_allocators(my_alloc, c_my_alloc) // expected-error {{non-predefined allocator must have traits specified}} expected-error {{expected variable of the 'omp_allocator_handle_t' type, not 'const omp_allocator_handle_t' (aka 'void **const')}}
    {
        // OpenMP block
    }

    return 0;
}
