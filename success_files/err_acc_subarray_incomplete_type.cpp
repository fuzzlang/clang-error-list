
// expected-error@+2{{OpenACC sub-array base is of incomplete type 'Incomplete'}}
// expected-note@#INCOMPLETE{{forward declaration of 'Incomplete'}}
struct Incomplete;

void example() {
    Incomplete *IncompletePtr;
    #pragma acc parallel private(IncompletePtr[0 :1])
    {
        // Some parallel code
    }
}
