
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    for (a : arr) {} // expected-error {{requires type for loop variable}}
    return 0;
}
