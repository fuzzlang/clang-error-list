
void check_cpu() {
    if (__builtin_cpu_is("power8")) // expected-error {{this builtin is available only on AIX 7.2 and later operating systems}}
        ;
}
