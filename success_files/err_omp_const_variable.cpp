
struct S1 {
    int data[10]; // Incomplete type for context
};
struct S2 {
    S2 operator+(const S2&) const;
private:
    int num;
};
struct S3 {
    S3 operator+(const S3&) const;
    int arr[20];
};

void func() {
    const int a = 1;
    const double b = 2.0;
    const char c = 'c';
    const int d = 4;
    const float f = 5.0f;
    S1 s1;
    S2 s2;
    S3 s3;
    
    #pragma omp distribute parallel for reduction(+ : a, b, c, d, f, s1, s2, s3)
    for (int i = 0; i < 10; i++) {
        // Loop body
    }
}
