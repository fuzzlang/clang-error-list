
struct S {
    int x;
    
    void f() {
        [x](){}; // expected-error{{class member 'x' cannot appear in capture list as it is not a variable}}
    }
};
