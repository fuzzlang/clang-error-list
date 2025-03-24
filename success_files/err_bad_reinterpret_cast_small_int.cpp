
void test() {
    int* ptr = nullptr;
    bool b = reinterpret_cast<bool>(ptr); // expected-error {{cast from pointer to smaller type 'bool' loses information}}
}
