
class Iter1 {
public:
    Iter1(float f = 0.0f, double d = 0.0) {}
    Iter1(const Iter1 &) {}
    Iter1 operator++() { return *this; }
    bool operator<(Iter1 a) { return true; }
};

int main() {
    Iter1 begin1, end1;

#pragma omp target parallel for simd
    for (Iter1 I = begin1; I < end1; ++I) // expected-error@+3 {{could not calculate number of iterations calling 'operator-' with upper and lower loop bounds}}
        ++I;

    return 0;
}
