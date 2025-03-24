
int main() {
    auto x = [&](__fp16 param) { return 0; }; // expected-error {{not allowed}}
    return 0;
}
