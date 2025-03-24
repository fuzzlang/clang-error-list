
#pragma omp declare reduction(
void myReductionFunction(int& a, int& b) {
    a += b;
}

int main() {
    int a = 0, b = 0;
    #pragma omp parallel
    {
        #pragma omp for reduction(+:a)
        for (int i = 0; i < 10; ++i) {
            a += i;
        }
    }
    return 0;
}
