
struct Two {
    int a;
    int b;
};

Two goo __attribute__((init_priority(2,3))) ( 5, 6 ); // expected-error {{'init_priority' attribute takes one argument}}
// unknown-warning@-1 {{unknown attribute 'init_priority' ignored}}

Two coo[2]  __attribute__((init_priority(100))); 
