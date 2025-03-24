
void example() {
    int *Pointer;
    #pragma acc parallel private(Pointer[1:])
    {
        // Some parallel code
    }
}
