
struct A {
    virtual consteval void f(); // expected-note {{overridden}}
    virtual void g(); // expected-note {{overridden}}
};

struct B : A {
    consteval void f();
    void g();
};

struct C : A {
    void f(); // expected-error {{non-consteval function 'f' cannot override a consteval function}}
    consteval void g(); // expected-error {{consteval function 'g' cannot override a non-consteval function}}
};
