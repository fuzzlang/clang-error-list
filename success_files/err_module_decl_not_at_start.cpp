
// expected-error@-2 {{missing 'module' declaration at end of global module fragment introduced here}}
#endif
#endif

extern int a; // #a1

#ifndef NO_MODULE_DECL
export module Foo; 
int b; // This line should trigger the expected error
#endif
