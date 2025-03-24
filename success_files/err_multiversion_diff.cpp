
// expected-error@+1 {{multiversioned function declaration has a different constexpr specification}}
constexpr int __attribute__((target("arch=sandybridge"))) foo(void); 
int __attribute__((target("arch=ivybridge"))) foo(void) { return 1; }
