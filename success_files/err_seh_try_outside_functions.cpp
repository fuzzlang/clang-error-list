
void use_seh_in_block() {
    void (^b)() = ^{ 
        __try { // expected-error {{cannot use SEH '__try' in blocks, captured regions, or Obj-C method decls}}
            // assumed function that might cause an exception
            int a = 0;
            int result = 10 / a; 
        } 
        __except(1) { 
        } 
    };
    try {
        b();
    } catch (int) {
    }
}
