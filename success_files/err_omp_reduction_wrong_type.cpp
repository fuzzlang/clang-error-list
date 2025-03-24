
#pragma omp declare reduction(+ : const int : \
    default(+:) initializer([]() { return 0; })

int main() {
    const int a = 5;
    const int b = 10;

#pragma omp parallel
    {
        int sum = 0;
#pragma omp atomic
        sum += a + b;
    }

    return 0;
}
