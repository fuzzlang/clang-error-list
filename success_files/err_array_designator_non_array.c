
struct point {
    double x;
    double y;
};

struct point p2 = {
    [1] = 1.0 // expected-error{{array designator cannot initialize non-array type}}
};
