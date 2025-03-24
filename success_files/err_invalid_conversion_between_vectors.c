
typedef long long t1 __attribute__ ((vector_size (8)));
typedef char t2 __attribute__ ((vector_size (16)));
typedef float t3 __attribute__ ((vector_size (16)));
typedef short s2 __attribute__ ((vector_size(4)));

void f(void) {
    t1 v1;
    t2 v2;
    s2 v4;

    v2 = (t2)v1; // expected-error {{invalid conversion between vector type 't2' (vector of 16 'char' values) and 't1' (vector of 1 'long long' value) of different size}}
}
