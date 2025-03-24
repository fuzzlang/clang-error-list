
int main() {
    int* a;
    float* c;
    
    bool eq1 = a == c;  // expected-error {{comparison of distinct pointer types}}
    
    return 0;
}
