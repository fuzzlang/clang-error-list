
int main() {
    auto s = 42;
    auto ([c]) = s; // expected-error {{decomposition declaration cannot be declared with parentheses}}
    return 0;
}
