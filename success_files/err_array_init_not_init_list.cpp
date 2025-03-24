
struct A {
    char i;
    double j;
};

struct C {
    A a;
    int b[20];
};

int main() {
    C c(A(1), 1, 2, 3, 4); // expected-error@-1 {{array initializer must be an initializer list}}
    return 0;
}
