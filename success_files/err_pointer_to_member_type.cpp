
struct C {
    static int (C::* a);
};

typedef void (C::*pmfc)();

void g(pmfc) {
    C *c;
    c->*pmfc(); // expected-error {{invalid use of pointer to member type after ->*}}
}
