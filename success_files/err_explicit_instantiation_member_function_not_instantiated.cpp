
struct X2 {
    int f0(int); // expected-note{{refers here}}
};

template int X2::f0(int); // expected-error{{not an instantiation}}
