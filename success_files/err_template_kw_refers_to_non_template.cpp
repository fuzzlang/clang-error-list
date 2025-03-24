
struct Y0 {
    void f3(int);
};

int main() {
    Y0::template f3(0); // expected-error {{'f3' following the 'template' keyword does not refer to a template}}
    return 0;
}
