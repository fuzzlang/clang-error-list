
typedef int *(*P)[3];
typedef const int *const (*S)[];

void testCast(P p) {
    (void) const_cast<S>(p); 
    // expected-error {{assigning to 'T' (aka 'const int *(*)[]') from 'S' (aka 'const int *const (*)[]') discards qualifiers}}
}
