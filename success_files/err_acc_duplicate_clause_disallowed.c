
int main() {
    #pragma acc kernels num_gangs(1) num_gangs(2)
    {
        // Some computation here
    }
    return 0;
}
