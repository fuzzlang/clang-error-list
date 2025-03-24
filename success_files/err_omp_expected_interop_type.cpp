
#pragma omp declare variant(foo_v4) match(construct={dispatch}) \
                                    append_args(interop(somethingelse))

void foo_v4() {}

int main() {
    #pragma omp target
    {
        foo_v4();
    }
    return 0;
}
