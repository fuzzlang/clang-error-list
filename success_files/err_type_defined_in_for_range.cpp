
int main() {
    int arr[] = {1, 2, 3};

    for (struct S { S(int) {} } s : arr) { // expected-error {{types may not be defined in a for range declaration}}
        // do something with s
    }

    return 0;
}
