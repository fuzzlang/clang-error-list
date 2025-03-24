
struct CompositeOfScalars {
    int I;
    float F;
    short J;
    char C;
    double D;
    _Complex float CF;
    _Complex double CD;
};

struct CompositeHasComposite {
    int I;
    float F;
    short J;
    char C;
    double D;
    _Complex float CF;
    _Complex double CD;
    struct CompositeOfScalars COS; // #COS_FIELD
};

void exampleFunction() {
    struct CompositeOfScalars CoS;
    struct CompositeHasComposite ChC;

    // expected-error@+2{{OpenACC 'reduction' composite variable must not have non-scalar field}}
    // expected-note@#COS_FIELD{{invalid field is here}}
    #pragma acc parallel reduction(&: ChC)
    {
        while (1);
    }
}
