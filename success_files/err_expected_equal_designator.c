
struct Point {
    int x;
};

void foo() {
    struct Point pt = {.x [10 METH2]};  // expected-error {{expected '=' or another designator}}
}
