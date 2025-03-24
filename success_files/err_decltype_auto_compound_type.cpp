
int main() {
    int i = 0;
    decltype(auto) *x7d = &i; // expected-error {{cannot form pointer to 'decltype(auto)'}}
    return 0;
}
