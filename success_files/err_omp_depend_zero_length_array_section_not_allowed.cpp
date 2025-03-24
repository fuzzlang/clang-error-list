
int main(int argc, char **argv) {
    #pragma omp task depend(in : argv[-1:0])
    {
    }
    return 0;
}
