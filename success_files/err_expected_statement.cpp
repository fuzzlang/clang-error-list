
// expected-error@-1 {{expected a type}}
void func() {
#if __cplusplus >= 201103L
    int arr[3];
    // The extra braces here are to avoid the parser getting too
    // badly confused when recovering here. We should fix this recovery.
    { for (const n
    // since-cxx11-error@-1 {{unknown type name 'n'}}
    //   since-cxx11-note@-2 {{}}
         : arr) ; {} }
#endif
}
