
int main() {
    [[clang::fallthrough]]; // expected-error{{fallthrough annotation is outside switch statement}}
    return 0;
}
