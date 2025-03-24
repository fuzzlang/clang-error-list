
int a = 0;

module; // expected-error {{'module;' introducing a global module fragment can appear only at the start of the translation unit}}

int main() {
    return 0;
}
