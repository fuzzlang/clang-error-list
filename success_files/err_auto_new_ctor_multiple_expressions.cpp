
int main() {
    new auto{1, 2, 3}; // expected-error {{new expression for type 'auto' contains multiple constructor arguments}}
}
