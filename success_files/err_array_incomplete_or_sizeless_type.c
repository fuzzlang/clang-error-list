
struct dr047_t;

struct dr047_t *dr047_2(struct dr047_t a[]) {
    return a;
} /* expected-error {{array has incomplete element type 'struct dr047_t'}} */
