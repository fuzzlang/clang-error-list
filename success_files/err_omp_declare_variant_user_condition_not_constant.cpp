
int foo() {
    return 42;
}

int bar() {
    return 24;
}

#pragma omp declare variant(foo) match(user = {condition(foo())}) // expected-error {{the user condition in the OpenMP context selector needs to be constant; foo() is not}}
int baz() {
    return 0;
}
