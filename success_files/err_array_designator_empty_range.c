
int main() {
    int arr[10] = {[8 ... 7] = 4}; // expected-error{{array designator range [8, 7] is empty}}
    return 0;
}
