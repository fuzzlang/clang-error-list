
int main() {
    int c = 1; // Narrowing occurs when a larger type (int) is converted to a smaller type (char) in initializer list.
    char ch = {'0' + c}; // expected-error {{cannot initialize}}
}
