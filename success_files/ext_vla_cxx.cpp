
int main() {
    int b = 5;
    typedef int T[b]; // expected-error {{variable length array}} expected-note {{initializer of 'b'}}
}
