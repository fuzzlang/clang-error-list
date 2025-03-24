
struct X {
    void operator delete(X*); // expected-error{{first parameter of 'operator delete' must have type 'void *'}}
};
