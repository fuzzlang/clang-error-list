
struct S {
    using array_type = int[10];
    operator array_type(); // expected-error{{conversion function cannot convert to an array type}}
};

int main() {
    S s;
    return 0;
}
