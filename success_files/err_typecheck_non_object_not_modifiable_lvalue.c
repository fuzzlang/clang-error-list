
void function(int param) {}

int main() {
    function = 0; // expected-error{{non-object type 'void (int)' is not assignable}}
    return 0;
}
