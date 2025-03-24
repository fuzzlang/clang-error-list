
void f(int i = 0); // expected-error {{C does not support default arguments}}

int main() {
    f();
    return 0;
}
