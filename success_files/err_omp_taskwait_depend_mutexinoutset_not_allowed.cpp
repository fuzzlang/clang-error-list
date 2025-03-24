
int main(int argc, char** argv) {
    #pragma omp taskwait depend(mutexinoutset: argc) // expected-error{{'mutexinoutset' modifier not allowed in 'depend' clause on 'taskwait' directive}}
    return 0;
}
