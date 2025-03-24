
void example() {
    int ArrayParam[5];

#pragma acc parallel private(ArrayParam[2:5])
    {
        // Some computation here
    }
}
