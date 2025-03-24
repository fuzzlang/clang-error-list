
__declspec(property(ptu=PutV)) int V4; // expected-error {{expected 'get' or 'put' in property declaration}}

int main() {
    return 0;
}
