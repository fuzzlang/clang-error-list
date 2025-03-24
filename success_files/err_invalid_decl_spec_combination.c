
void func() {
    __thread auto int t12a; // expected-error-re {{cannot combine with previous '{{__thread|_Thread_local}}' declaration specifier}}
}
