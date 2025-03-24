
struct A {
    int &i;
};

int main() {
    A a;
    a.*&A::i = 10; // expected-error{{cannot form a pointer-to-member to member 'i' of reference type 'int &'}}
    return 0;
}
