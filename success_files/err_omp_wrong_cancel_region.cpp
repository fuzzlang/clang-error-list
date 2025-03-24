
int main() {
    #pragma omp cancel // expected-error {{one of 'for', 'parallel', 'sections' or 'taskgroup' is expected}}
    return 0;
}
