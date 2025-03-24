
void pr23151(int (&)[*]) { // expected-error {{variable length array must be bound in function definition}}
}
