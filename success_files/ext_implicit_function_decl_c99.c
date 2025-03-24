
static void f(int p, ...) {
    __gnuc_va_list g; // c89-error{{undeclared identifier '__gnuc_va_list'}} c99-error{{undeclared identifier}} \
                         c89-modules-error{{undeclared identifier}} c99-modules-error{{undeclared identifier}}
    va_list v; // c89-error{{undeclared identifier 'va_list'}} c99-error{{undeclared identifier}} \
                  c89-modules-error{{undeclared identifier}} c99-modules-error{{undeclared identifier}}
    va_start(v, p); // c89-error{{implicitly declaring library function 'va_start'}} c89-note{{include the header <stdarg.h> or explicitly provide a declaration for 'va_start'}} c89-error{{undeclared identifier 'v'}} \
                       c99-error{{call to undeclared library function 'va_start'}} c99-note{{provide a declaration}} c99-error{{undeclared identifier}} \
                       c89-modules-error{{implicitly declaring library function}} c89-modules-note{{provide a declaration}} c89-modules-error{{undeclared identifier}} \
                       c99-modules-error{{undeclared library function}} c99-modules-note{{provide a declaration}} c99-modules-error{{undeclared identifier}}
    int i = va_arg(v, int); // c89-error{{implicit declaration of function 'va_arg'}} c89-error{{expected expression}} c89-error{{use of undeclared identifier 'v'}} 
}
