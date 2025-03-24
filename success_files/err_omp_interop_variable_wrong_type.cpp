
// expected-error@+1 {{interop variable must be of type 'omp_interop_t'}}
typedef void *omp_interop_t;

int main() {
    int IntVar;
    #pragma omp interop init(prefer_type(1,"sycl",3),target:IntVar) 
    {
        // Some code here
    }
    return 0;
}
