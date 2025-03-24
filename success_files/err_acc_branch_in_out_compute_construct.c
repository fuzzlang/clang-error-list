
void BreakContinue() {
    #pragma acc parallel
    for(int i = 0; i < 5; ++i) {
        break;  // expected-error{{invalid branch out of OpenACC Compute Construct}}
    }
}
