
class pr16989 {
    void tpl_mem(int *) {
        return;
        class C2 {
            void f();  // declaration
        };
        void C2::f() {} // expected-error{{function definition is not allowed here}}
    };
};
