
void atomic_ops_test() {
    atomic_int i;
    
    i = 1; // expected-error {{atomic variable can be assigned to a variable only in global address space}}
}
