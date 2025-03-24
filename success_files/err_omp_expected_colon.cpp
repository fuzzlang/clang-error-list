
void test() {
#pragma omp metadirective when(device{arch(nvptx)}) // expected-error {{missing ':' in when clause}} expected-error {{expected expression}} expected-warning {{expected '=' after the context set name "device"; '=' assumed}}
{
    // Code block
}
}
