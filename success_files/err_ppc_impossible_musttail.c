
__attribute__((weak)) int func2(int i) {
  return 0;
}

int external_call2(int i) {
  // linux-error@+2 {{'musttail' attribute for this call is impossible because external calls can not be tail called on PPC}}
  // aix-error@+1 {{'musttail' attribute is not supported on AIX}}
  [[clang::musttail]] return func2(i);
}
