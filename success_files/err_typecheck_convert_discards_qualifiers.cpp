
typedef int *R[3]; 
typedef const int *const S[];
typedef const int *T[];
typedef int *const P[3];
typedef const int *const Q[3];
typedef const int *const Q2[3];

void test() {
    R *r;
    S *s;
    T *t;
    P *p;
    Q *q;
    Q2 *q2;

    s = q;  // expected-error {{incompatible pointer types assigning to 'S' (aka 'const int *const (*)[]') from 'Q' (aka 'const int *const (*)[3]')}}
    s = q2; // expected-error {{incompatible pointer types assigning to 'S' (aka 'const int *const (*)[]') from 'Q2' (aka 'const int *const (*)[3]')}}
    s = t;  // ok, adding const
    t = s;  // expected-error {{incompatible pointer types assigning to 'T' (aka 'const int *(*)[]') from 'S' (aka 'const int *const (*)[]')}}
}
