
// expected-error@-1 {{'P' cannot be defined in a type specifier}}
#if __cplusplus < 201703L
    void g() throw(struct P);
#endif
