
void testFunction() {
    // This will trigger the expected error due to invalid argument type
    #pragma clang loop pipeline_initiation_interval(1.0)
    for (int i = 0; i < 10; ++i) {
        // Loop body
    }
}
