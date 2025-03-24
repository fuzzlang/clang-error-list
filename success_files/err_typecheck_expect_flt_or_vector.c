
typedef struct {
    int value;
} stype;

void example_function() {
    stype s;

    s = __arithmetic_fence(s);    // expected-error {{invalid operand of type 'stype' where floating, complex or a vector of such types is required}}
}
