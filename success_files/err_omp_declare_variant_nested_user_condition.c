
int foo();

#pragma omp begin declare variant match(user = {condition(1)})
#pragma omp declare variant(foo) match(user = {condition(1)}) // expected-error {{nested user conditions in OpenMP context selector not supported (yet)}}
void nested_user_conditions() {
    // Function body
}
#pragma omp end declare variant
