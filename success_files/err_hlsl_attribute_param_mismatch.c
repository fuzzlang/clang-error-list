
[numthreads(1,1,1)]
void foo();

[numthreads(2,2,2)]  // expected-error {{'numthreads' attribute parameters do not match the previous declaration}}
void foo() {
}
