
struct incomplete; // Forward declaration of incomplete type

void example() {
    struct incomplete *ptr; // Pointer to an incomplete type

    *(ptr) = '0'; // expected-error {{incomplete type 'void' is not assignable}}
}
