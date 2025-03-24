
class X {
public:
    enum E { Enumerator }; // expected-note 2{{declared here}}
    int f();
    static int mem;
    static float g();
};

void test(X* xp, X x) {
    x.E; // expected-error{{cannot refer to type member 'E' in 'X' with '.'}}
    return;
}
