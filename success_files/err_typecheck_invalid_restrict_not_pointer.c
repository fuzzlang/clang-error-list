
struct S {
    int arr[2];
};

void func() {
    restrict S y; // expected-error {{restrict requires a pointer or reference ('S' (aka 'int *[2]') is invalid)}}
}
