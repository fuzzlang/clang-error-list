
typedef float fltx4 __attribute__((__vector_size__(16)));

template <typename T>
struct DiagTrunc {
    static constexpr double k = 1340282346638528859811704183484516925443.000000;
    fltx4 f(fltx4 x) {
        // expected-error@+1{{as implicit conversion would cause truncation}}
        return k * x;
    }
};

void use() {
    fltx4 theFloat4;
    DiagTrunc<double>().f(theFloat4);
}
