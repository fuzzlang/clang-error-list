
auto l = [=] {}; // expected-error {{non-local lambda expression cannot have a capture-default}}

struct S {
    int n;
    int (*f())[true ? 1 : ([=]{ return n; }(), 0)]; // expected-error {{non-local lambda expression cannot have a capture-default}}
};
