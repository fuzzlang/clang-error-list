
void test_reduction_error() {
    int r = 0;
    #pragma omp parallel reduction(+:r) 
    {
        #pragma omp task
        {
            ++r;  // expected-error@+1 {{reduction variables may not be accessed in an explicit task}}
        }
    }
}
