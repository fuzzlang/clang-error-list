
struct S {
    int x : 3;
};

int main() {
    struct S *P;
    int R;

    R = __alignof__(P->x);  // expected-error {{invalid application of 'alignof' to bit-field}}
    
    return 0;
}
