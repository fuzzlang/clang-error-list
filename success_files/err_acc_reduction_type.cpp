
void func() {
    int Array[5];

    #pragma acc parallel reduction(&: Array) {
        // Code block
    }
}
