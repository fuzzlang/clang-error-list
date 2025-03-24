
typedef void (^bptr)(void);

bptr foo5(int j) {
    __block int i;
    if (j)
        return ^{ ^{ i = 0; }(); };  // expected-error {{returning block that lives on the local stack}}
    return ^{ i = 0; };  
}
