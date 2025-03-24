
struct S1; // Incomplete type

class S2 {
    mutable int a;
public:
    S2() : a(0) {}
};

class S3 {
    int a;
public:
    S3() : a(0) {} // Default constructor
};

extern S1 a;
const S2 b;
const S3 c; // No matching constructor
extern const int f;

int main(int argc, char **argv) {
    int i;

#pragma omp target teams distribute parallel for firstprivate(a, b, c, d, f) // expected-error {{firstprivate variable with incomplete type 'S1'}} expected-error {{no matching constructor for initialization of 'S3'}}
    for (i = 0; i < argc; ++i) {
        // Loop body
    }

    return 0;
}
