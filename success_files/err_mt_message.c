
__strong void *gcVar; // expected-error {{GC managed memory will become unmanaged in ARC}}

int main() {
    return 0;
}
