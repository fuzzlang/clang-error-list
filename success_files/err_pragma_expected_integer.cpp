
int main() {
    #pragma clang max_tokens_here foo // expected-error {{expected an integer argument in '#pragma clang max_tokens_here'}}
}
