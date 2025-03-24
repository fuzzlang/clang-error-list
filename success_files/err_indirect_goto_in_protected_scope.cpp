
namespace test4 {
    struct C { C(); };

    void f(void **ip) {
        static void *ips[] = { &&lbl1, &&lbl2 };

        C c0;
        goto *ip; // expected-error {{cannot jump}}
        C c1; // expected-note {{jump bypasses variable initialization}}

      lbl1: // expected-note {{possible target of indirect goto}}
        return 0;

      lbl2:
        return 1;
    }
}
