
struct Padded2 { 
    char x; 
    int y; 
};

// expected-warning@+2 {{padding struct}}
// expected-error@+4 {{padding struct}}
int arr2[sizeof(Padded2)];
