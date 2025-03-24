
int main() {
    float f = (float)nullptr;       // expected-error {{cannot cast an object of type 'nullptr_t' to 'float'}}
    return 0;
}
