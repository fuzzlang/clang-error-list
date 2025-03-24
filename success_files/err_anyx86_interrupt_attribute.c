
__attribute__((interrupt)) int foo1(void) { 
    return 0; 
} // expected-error-re {{{{(x86|x86-64)}} 'interrupt' attribute only applies to functions that have a 'void' return type}}
