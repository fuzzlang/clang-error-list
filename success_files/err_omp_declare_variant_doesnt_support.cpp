
constexpr int fn_constexpr() { return 42; }
#pragma omp declare variant(fn_constexpr) match(implementation = {}) // expected-error {{'#pragma omp declare variant' does not support constexpr functions}} expected-warning {{expected identifier or string literal describing a context selector; selector skipped}} expected-note {{context selector options are: 'vendor' 'extension' 'unified_address' 'unified_shared_memory' 'reverse_offload' 'dynamic_allocators' 'atomic_default_mem_order'}} expected-note {{the ignored selector spans until here}}
int main() {
    return fn_constexpr();
}
