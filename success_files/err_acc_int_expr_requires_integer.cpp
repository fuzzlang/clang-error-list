
struct NotConvertible {};

void foo() {
    NotConvertible NC;
    int SomeE;

    #pragma acc parallel num_gangs(NC, SomeE) // expected-error@+1{{OpenACC clause 'num_gangs' requires expression of integer type ('struct NotConvertible' invalid)}}
    {
        // parallel code
    }
}
