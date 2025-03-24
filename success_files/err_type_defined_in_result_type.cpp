
struct S5 { int x; } f1() { 
    return S5(); 
} // expected-error{{result type}}
