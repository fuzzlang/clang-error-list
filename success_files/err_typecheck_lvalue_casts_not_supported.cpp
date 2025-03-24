
int main() {
    int a = 5;
    int(b) = int(a)++; // expected-error {{assignment to cast is illegal}}
    return 0;
}
