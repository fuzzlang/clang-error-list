
void barbar(int *, int *, int *, int *) {}

#pragma omp declare variant(barbar) match(implementation = {}) // expected-error {{variant in '#pragma omp declare variant' with type '<overloaded function type>' is incompatible with type 'void (int *, int *, int *, int *)'}} expected-warning {{expected identifier or string literal describing a context selector; selector skipped}} expected-note {{context selector options are: 'vendor' 'extension' 'unified_address' 'unified_shared_memory' 'reverse_offload' 'dynamic_allocators' 'atomic_default_mem_order'}} expected-note {{the ignored selector spans until here}}

void foo() {
    int a, b, c, d;
    barbar(&a, &b, &c, &d);
}
