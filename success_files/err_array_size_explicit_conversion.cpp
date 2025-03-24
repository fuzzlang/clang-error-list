
struct Int {
    operator int();
};

struct NotInt {
    explicit operator int(); // expected-note {{conversion to integral type 'int' declared here}}
};

Int i;
NotInt ni;

void testNew() {
    new int[i];
    new int[ni]; // expected-error {{array size expression of type 'NotInt' requires explicit conversion to type 'int'}}
}
