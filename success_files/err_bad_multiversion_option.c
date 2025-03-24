
//expected-error@+1 {{function multiversioning doesn't support feature 'default'}}
void __attribute__((target_version("default+fp16"))) koo(void) {}
