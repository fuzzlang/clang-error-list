
struct S {
    int b;
};

S h;

void example() {
    #pragma omp distribute parallel for reduction(max : h.b) 
    {
        // Loop code here
    }
}
