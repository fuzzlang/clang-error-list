
__declspec(property(get=)) int V7; // expected-error {{expected name of accessor method}}

int main() {
    return 0;
}
