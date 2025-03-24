
struct {
    unsigned : -2;  // expected-error {{anonymous bit-field has negative width (-2)}}
} example;
