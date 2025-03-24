
struct C; // expected-note{{forward declaration}}

void test_incomplete_object_call(C& c) {
    c(); // expected-error{{incomplete type in call to object of type}}
}
