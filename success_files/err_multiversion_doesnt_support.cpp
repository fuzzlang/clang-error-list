
// expected-error@+2 {{multiversioned functions do not yet support function templates}}
template<typename T>
int __attribute__((target("default"))) foo(T) { return 2; }

// expected-error@+2 {{multiversioned functions do not yet support function templates}}
template<typename T>
int __attribute__((target("foo"))) bar(T) { return 3; }
