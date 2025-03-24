
struct A {
    int value;
};

A test;
A test1;

void function() {
#pragma omp parallel reduction(+ : test) reduction(::operator+: test1) // expected-error {{unable to resolve declare reduction construct for type 'A'}}
    {
        test.value += 1;
        test1.value += 1;
    }
}
