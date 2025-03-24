
int main() {
    unsigned long long b;
    int a;

    asm volatile("foo %0 %1" : "=a" (a) :"0" (b)); // expected-error {{input with type 'unsigned long long' matching output with type 'int'}}
    
    return 0;
}
