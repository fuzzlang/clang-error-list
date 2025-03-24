
// expected-error@+1 {{'main' cannot be a multiversioned function}}
int __attribute__((target_clones("sve-i8mm"))) main() { return 1; }
