
int main() {
    int a = 5, v = 3;

#pragma omp atomic compare release weak
    if (v < a) { v = a; }

    return 0;
}
