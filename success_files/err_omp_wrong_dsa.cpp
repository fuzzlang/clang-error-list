
class S2 {
public:
    static int S2s;
};

int S2::S2s = 0;

void exampleFunction() {
    #pragma omp distribute parallel for reduction(&& : S2::S2s) // expected-error {{shared variable cannot be reduction}}
    for (int i = 0; i < 10; ++i) {
        S2::S2s += i;
    }
}
