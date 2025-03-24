
void __attribute__((target("default"))) addtl_attrs2(void); 
// expected-error@+2 {{multiversioning attributes cannot be combined}} 
void __attribute__((cpu_specific(sandybridge))) addtl_attrs2(void); 
