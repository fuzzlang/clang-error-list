
struct S {
    int arr[10];
};

S s;

int main() {
    (void)s.arr[ [] { return 0; }() ]; // expected-error {{C++11 only allows consecutive left square brackets when introducing an attribute}}
    return 0;
}
