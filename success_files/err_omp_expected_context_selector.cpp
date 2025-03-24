
int main() {
    #pragma omp metadirective when() // expected-error {{expected valid context selector in when clause}} expected-error {{expected expression}} expected-warning {{expected identifier or string literal describing a context set; set skipped}} expected-note {{context set options are: 'construct' 'device' 'implementation' 'user'}} expected-note {{the ignored set spans until here}}
    {
        // Code block for OpenMP directive
    }
    return 0;
}
