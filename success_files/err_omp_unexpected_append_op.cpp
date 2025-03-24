
void foo_v1() {}

#pragma omp declare variant(foo_v1) match(construct={dispatch}) \
                                    append_args(foobar(target)) // expected-error {{unexpected operation specified in 'append_args' clause, expected 'interop'}}

int main() {
    return 0;
}
