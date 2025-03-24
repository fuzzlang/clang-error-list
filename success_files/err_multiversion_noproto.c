
// expected-error@+1 {{multiversioned function must have a prototype}}
int __attribute__((cpu_specific(atom))) no_proto() {
    return 0;
}
