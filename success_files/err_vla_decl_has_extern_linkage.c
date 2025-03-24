
void test_vla_extern_linkage(int n) {
   extern int bad[n];  /* expected-error {{variable length array declaration cannot have 'extern' linkage}} */
}
