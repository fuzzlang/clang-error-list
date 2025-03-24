
// expected-error@+1 {{hidden visibility cannot be applied to 'dllexport' declaration}}
__attribute__((dllexport)) __attribute__((visibility("hidden"))) void exported_hidden() { }
