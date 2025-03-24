
class A {
public:
    void func() {
        #pragma omp target map(this[:2]) // expected-note {{expected length on mapping of 'this' array section expression to be '1'}} // expected-error {{invalid 'this' expression on 'map' clause}}
        {
            // Some code here
        }
    }
};
