
struct S1; // Forward declared to create an incomplete type.

class S2 {
  mutable int a{}; // mutable is necessary to solve a part of requested error
public:
  S2() : a(0) {}
};

const S2 b; // const-qualified

struct S3 {
public:
  S3() {}
};

const S3 c; // const-qualified without mutable fields

extern const int f; // const-qualified

void example() {
    extern S1 a; // S1 is incomplete
    const int d = 5; // const-qualified
    #pragma omp target teams distribute simd private(a, b, c, d, f) 
    {
    }
}
