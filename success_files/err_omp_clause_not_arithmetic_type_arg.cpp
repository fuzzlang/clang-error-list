
struct S1; // Incomplete type
struct S2 {
    int x;
    S2() : x(0) {}
};
struct S3 {
    double y;
    S3() : y(0.0) {}
};

void foo() {
    const S2 a = S2();
    S2 b;
    S1 c; // Incomplete type
    S3 d; // Not trivially copyable
    const S2 f = S2(); // const-qualified variable

#pragma omp distribute parallel for reduction(min : a, b, c, d, f) // expected-error {{a reduction list item with incomplete type 'S1'}} expected-error 2 {{arguments of OpenMP clause 'reduction' for 'min' or 'max' must be of arithmetic type}} expected-error 2 {{const-qualified variable cannot be reduction}} expected-error {{incomplete type 'S1' where a complete type is required}} expected-warning {{type 'S2' is not trivially copyable and not guaranteed to be mapped correctly}} expected-warning {{type 'S3' is not trivially copyable and not guaranteed to be mapped correctly}}
    for (int i = 0; i < 10; ++i) {
        // Some computations
    }
}
