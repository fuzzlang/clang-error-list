
int main() {
    new auto{}; // expected-error{{new expression for type 'auto' requires a constructor argument}}
    return 0;
}
