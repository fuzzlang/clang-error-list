
int main() {
    int Parm = 0;
    int IVar = 0;

    #pragma acc parallel reduction(+:Parm) num_gangs(Parm, IVar) // expected-error{{OpenACC 'reduction' clause may not appear on a 'parallel' construct with a 'num_gangs' clause with more than 1 argument, have 2}}
    {
        Parm += 1;
    }
    
    return 0;
}
