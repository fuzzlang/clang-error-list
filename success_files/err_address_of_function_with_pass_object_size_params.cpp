
void Foo(void *ptr __attribute__((pass_object_size(1)))) {}

int main() {
    int (*A)(void *) = &Foo; // expected-error{{cannot take address of function 'Foo' because parameter 1 has pass_object_size attribute}}
}
