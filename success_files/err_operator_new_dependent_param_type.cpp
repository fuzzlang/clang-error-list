
template <typename T>
void* operator new(T size, int); // expected-error {{'operator new' cannot take a dependent type as first parameter; use size_t}}

void func() {
    void* ptr = new (42) int; // This line is where the error should be triggered
}
