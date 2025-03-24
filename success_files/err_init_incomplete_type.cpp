
namespace PR12498 {
    class ArrayRef; // expected-note{{forward declaration}}

    struct C {
        void foo(const ArrayRef&); // expected-note{{passing argument to parameter here}}
    };

    static void bar(C* c) {
        c->foo({ nullptr, 1 }); // expected-error{{initialization of incomplete type 'const ArrayRef'}}
    }
}
