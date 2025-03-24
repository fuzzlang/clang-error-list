
void test() {
    int e1;
    int e1b;

    void(e1 <=> e1b); // expected-error {{include <compare>}}
}
