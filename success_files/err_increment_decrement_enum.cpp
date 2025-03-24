
enum A { VAL1, VAL2, VAL3 };

int main() {
    A a = VAL1;
    a++;  // expected-error{{cannot increment expression of enum type 'A'}}
    return 0;
}
