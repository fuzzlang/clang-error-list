
struct SB {
    unsigned A;
    unsigned B;
    float Arr[100];
    float *Ptr;
};

struct SC {
    SB *PtrS;
    SB *&RPtrS;
    SC(SB *&_RPtrS) : RPtrS(_RPtrS) {}
};

void test() {
    SB *p;
    SC r(p);
    
    #pragma omp target map(r.PtrS[0], r.PtrS->B) // lt50-error {{same pointer dereferenced in multiple different ways in map clause expressions}} lt50-note {{used here}}
    {}
}
