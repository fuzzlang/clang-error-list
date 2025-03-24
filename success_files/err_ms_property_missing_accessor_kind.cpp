
__declspec(property(ptu)) int V3; // expected-error {{missing 'get=' or 'put='}}

int main() {
    return 0;
}
