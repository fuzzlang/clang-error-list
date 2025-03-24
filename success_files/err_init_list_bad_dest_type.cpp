
struct Empty {};

struct Foo : Empty {
    int x;
    int y;
};

int f();

void reproduceError() {
#if __cplusplus <= 201703L
    Foo o = (Foo){ {}, 1, f() }; // expected-error {{initializer element is not a compile-time constant}}
#endif
}
