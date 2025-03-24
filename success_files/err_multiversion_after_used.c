
int allow_fwd_decl2(void);
void use_fwd_decl(void) {
  allow_fwd_decl2();
}
// expected-error@+1 {{function declaration cannot become a multiversioned function after first usage}}
int __attribute__((cpu_dispatch(atom))) allow_fwd_decl2(void) {}
