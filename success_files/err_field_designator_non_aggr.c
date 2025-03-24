
struct point {
    double x;
    double y;
};

struct point array3[10] = {
    .x = 5 // expected-error{{field designator cannot initialize a non-struct, non-union type}}
};
