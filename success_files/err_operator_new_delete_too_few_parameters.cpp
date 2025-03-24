
inline void* operator new(); // expected-error {{'operator new' must have at least one parameter}}

int main() {
    return 0;
}
