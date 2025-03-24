
int main() {
    #pragma clang loop unroll_and_jam(4) // expected-error {{invalid option 'unroll_and_jam'; expected vectorize, vectorize_width, interleave, interleave_count, unroll, unroll_count, pipeline, pipeline_initiation_interval, vectorize_predicate, or distribute}}
    for (int i = 0; i < 10; ++i) {
        // Do something
    }
    return 0;
}
