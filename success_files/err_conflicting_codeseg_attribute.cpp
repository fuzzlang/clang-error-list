
// expected-error@-1 {{overriding virtual function must specify the same code segment as its overridden function}}
// expected-note@67 {{previous declaration is here}}

class Base {
public:
    virtual int __declspec(code_seg("foo")) func() { return 0; }
};

class Derived : public Base {
public:
    // expected-error@-1 {{overriding virtual function must specify the same code segment as its overridden function}}
    virtual int __declspec(code_seg("bar")) func() override { return 1; } 
};

// Function
int __declspec(code_seg("foo")) __declspec(code_seg("foo")) bar1() { return 1; }
// expected-warning@-1 {{duplicate code segment specifiers}}
int __declspec(code_seg("foo")) __declspec(code_seg("bar")) bar2() { return 1; }
