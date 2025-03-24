
static int static_var;

_Static_assert(1, ""); // expected-error {{expected ';' after '_Static_assert'}} \
                       // ext-warning {{'_Static_assert' is a C11 extension}}
_Static_assert(&static_var != 0, "");  // ext-warning {{'_Static_assert' is a C11 extension}} \
                                        // expected-warning {{comparison of address of 'static_var' not equal to a null pointer is always true}}
_Static_assert("" != 0, "");            // ext-warning {{'_Static_assert' is a C11 extension}}
_Static_assert(("" != 0), "");          // ext-warning {{'_Static_assert' is a C11 extension}}
_Static_assert(*"1", "");                // ext-warning {{'_Static_assert' is a C11 extension}}
_Static_assert("1"[0], "");              // ext-warning {{'_Static_assert' is a C11 extension}}
_Static_assert(1.0 != 0, "");             // ext-warning {{'_Static_assert' is a C11 extension}}
_Static_assert(__builtin_strlen("1"), ""); // ext-warning {{'_Static_assert' is a C11 extension}}

#ifndef __cplusplus
// expected-warning@-9 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}}
// expected-warning@-8 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}}
// expected-warning@-8 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}}
// expected-warning@-8 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}}
// expected-warning@-8 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}}
// expected-warning@-8 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}} 
#endif

_Static_assert(0, L"\xFFFFFFFF"); // expected-warning {{encoding prefix 'L' on an unevaluated string literal has no effect}} \
