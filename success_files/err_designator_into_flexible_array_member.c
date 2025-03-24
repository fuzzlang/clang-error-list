
struct flex {
    int points[]; // flexible array member
};

struct flex example = {
    .points[2] = { 1, 2 } // expected-error{{designator into flexible array member subobject}}
};
