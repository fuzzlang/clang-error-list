
struct B {};
struct A {};

int main() {
    B *bp1;
    (void)static_cast<A *>(bp1); // expected-error{{is not allowed}}
    return 0;
}
