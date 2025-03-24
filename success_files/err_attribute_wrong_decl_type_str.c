
__attribute__((mode(QI))) int invalid_func(void) { 
    return 1; 
} // expected-error{{'mode' attribute only applies to variables, enums, typedefs, and non-static data members}}
