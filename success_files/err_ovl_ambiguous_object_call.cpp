
namespace cwg280 {
    typedef void f0();
    typedef void f1(int);
    typedef void f2(int, int);
    typedef void f3(int, int, int);
    
    struct A {
        operator f1*(); // #cwg280-A-f1
        operator f2*();
    };

    struct B {
        operator f0*(); // #cwg280-B-f0
    private:
        operator f3*(); // #cwg280-B-f3
    };

    struct C {
        operator f0*(); // #cwg280-C-f0
        operator f1*(); // #cwg280-C-f1
        operator f2*(); // #cwg280-C-f2
        operator f3*(); // #cwg280-C-f3
    };

    struct D : private A, B { // #cwg280-D
        operator f2*(); // #cwg280-D-f2
    } d;

    struct E : C, D {} e;

    void g() {
        e(); // expected-error@-1 {{call to object of type 'struct E' is ambiguous}}
              //   expected-note@#cwg280-B-f0 {{conversion candidate of type 'void (*)()'}}
              //   expected-note@#cwg280-C-f0 {{conversion candidate of type 'void (*)()'}}
    }
}
