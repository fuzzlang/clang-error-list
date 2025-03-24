
int main() {
    if (__builtin_cpu_is("int")) // expected-error {{invalid cpu name for builtin}}
        ;
    return 0;
}
