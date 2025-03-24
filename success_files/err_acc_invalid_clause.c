
int main() {
    // expected-error@+2{{invalid OpenACC clause 'invalid'}}
    // expected-warning@+1{{OpenACC construct 'enter data' not yet implemented, pragma ignored}}
    #pragma acc enter data finalize invalid
    return 0;
}
