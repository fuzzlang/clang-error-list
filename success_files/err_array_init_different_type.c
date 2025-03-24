
int main() {
    int a6[5] = (int[]){1, 2, 3}; // expected-error{{cannot initialize array of type 'int[5]' with array of type 'int[3]'}}
    return 0;
}
