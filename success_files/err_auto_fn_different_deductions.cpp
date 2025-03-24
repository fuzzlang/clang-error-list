
auto func() {
    return; // expected-error {{'auto' in return type deduced as 'int' here but deduced as 'void' in earlier return statement}}
    return 0;
}
