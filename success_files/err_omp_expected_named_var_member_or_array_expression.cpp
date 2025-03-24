
struct SB {
    unsigned A;
    unsigned B;
    float Arr[100];
    float *Ptr;
    float *foo() {
        return &Arr[0];
    }
};

struct SC {
    unsigned A : 2;
    unsigned B : 3;
    unsigned C;
    unsigned D;
    float Arr[100];
    SB S;
    SB ArrS[100];
    SB *PtrS;
    SB *&RPtrS;
    
    SC(SB *&_RPtrS) : RPtrS(_RPtrS) {}
};

void func() {
    SC r(nullptr);
    
    #pragma omp target map(r.S.foo() [:12]) // lt50-error {{expected expression containing only member accesses and/or array sections based on named variables}} ge50-error {{expected addressable lvalue in 'map' clause}} 
    {}
}
