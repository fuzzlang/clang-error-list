
void foo() {
    #pragma acc loop collapse(unknown:)
    for (int i = 0; i < 10; i++) {
        // loop body
    }
}
