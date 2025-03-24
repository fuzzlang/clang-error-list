
namespace cwg142 {
    class B { // #cwg142-B
    public:
        int mi; // #cwg142-B-mi
        static int si; // #cwg142-B-si
    };
    
    class D : private B { // #cwg142-D
    };

    class DD : public D {
    public:
        void f();
    };

    void DD::f() {
        B *bp1_old = this; // #cwg142-bp1_old
        // expected-error@#cwg142-bp1_old {{'B' is a private member of 'cwg142::B'}}
        //   expected-note@#cwg142-D {{constrained by private inheritance here}}
        //   expected-note@#cwg142-B {{member is declared here}}
    }
}
