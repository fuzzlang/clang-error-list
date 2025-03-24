
union u {
    int a;
    float b;
};

void function() {
    int *x;
    f((union u)&x); // expected-error {{cast to union type from type 'int *' not present in union}}
}
