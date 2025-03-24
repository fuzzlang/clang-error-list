
enum x;

int main() {
    (enum x)1;   // expected-error {{cast to incomplete type}}
    return 0;
}
