
struct Q {
    int a;
};

void g() { 
    Q q = {.a = 1}; // expected-error {{initialization of non-aggregate type 'Q' with a designated initializer list}} 
}

struct S { 
    int a; 
};

void h(Q q);
void h(S s);

void i() {
    h({.a = 1}); 
}

namespace GH63605 {
    struct A {
        unsigned x;
        unsigned y;
        unsigned z;
    };

    struct B {
        unsigned a;
        unsigned b;
    };

    struct : public A, public B {
        unsigned : 2;
        unsigned a : 6;
        unsigned : 1;
        unsigned b : 6;
        unsigned : 2;
        unsigned c : 6;
        unsigned d : 1;
        unsigned e : 2;
    } data = {
        {.z = 0, 
         // pedantic-note@-1 {{first non-designated initializer is here}}
         // reorder-note@-2 {{previous initialization for field 'z' is here}}
         .y = 1, // reorder-error {{field 'z' will be initialized after field 'y'}}
         // reorder-note@-1 {{previous initialization for field 'y' is here}}
         .x = 2} // reorder-error {{field 'y' will be initialized after field 'x'}}
    };
}
