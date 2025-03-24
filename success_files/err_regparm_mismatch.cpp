
class X0 {
public:
    void __attribute__((regparm(3))) f2();
    void __attribute__((regparm(2))) f2(); // expected-error{{function declared with regparm(2) attribute was previously declared with the regparm(3) attribute}}
};

void X0::f2() { }
