
struct Incomplete;

void exampleFunction() {
    Incomplete *I;
    #pragma acc parallel private(*I) // expected-error@+1{{OpenACC variable is not a valid variable name, sub-array, array element, member of a composite variable, or composite variable member}}
    {
        while(true);
    }
}
