
typedef unsigned long long u_int64_t;
typedef u_int64_t uint64_t;

int main() {
    uint64_t val = 0;
    __asm__ volatile("foo1 %0" : "=R" (val)); // expected-error {{invalid output size for constraint '=R'}}
    return 0;
}
