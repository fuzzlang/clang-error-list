
struct C { 
    int a[2]; 
    C() : a({1, 2}) { } // expected-error {{parenthesized initialization of a member array is a GNU extension}} 
}; 
