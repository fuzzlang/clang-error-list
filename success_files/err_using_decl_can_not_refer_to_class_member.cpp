
class X {
public:
    static int i;
};

void example() {
    using X::i; // expected-error{{using declaration cannot refer to class member}}
}
