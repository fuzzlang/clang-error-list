
namespace cwg198 { // cwg198: yes
    struct A {
        int n;
        struct B {
            int m[sizeof(n)]; // expected-error@-1 {{invalid use of non-static data member 'n'}}
        };
    };
}
