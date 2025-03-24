
#pragma omp declare variant(foo_v4)                          \
                    match(construct={target}) append_args(interop(target))

void someFunction() {
    // Some logic here
}
