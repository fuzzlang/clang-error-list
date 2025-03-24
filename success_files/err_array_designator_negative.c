
int main() {
    int arr[10] = {[ -1 ] = 6}; // expected-error{{array designator value '-1' is negative}}
    return 0;
}
