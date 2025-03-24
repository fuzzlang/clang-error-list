
class TestClass {
public:
    int a;
    TestClass(int x) : a(x) {}
};

int main() {
    int y = 10;
    static TestClass LocalClass(y); // expected-error {{variable with local storage in initial value of threadprivate variable}}
    #pragma omp threadprivate(LocalClass)
}
