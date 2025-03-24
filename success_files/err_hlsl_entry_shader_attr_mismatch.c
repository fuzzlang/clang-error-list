
// expected-error@+1 {{'shader' attribute on entry function does not match the target profile}}
[numthreads(1,1,1), shader("mesh")]
void foo() {
}
