
typedef long long t1 __attribute__ ((vector_size (8)));
typedef char t2 __attribute__ ((vector_size (16)));
typedef short s2 __attribute__ ((vector_size(4)));

void f(void) {
    t1 v1;
    t2 v2;
    s2 v4;

    v1 = (t1)(short)10; // expected-error {{invalid conversion between vector type 't1' (vector of 1 'long long' value) and integer type 'short' of different size}}
}
