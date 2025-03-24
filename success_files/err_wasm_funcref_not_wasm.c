
typedef void (*__funcref funcref_t)();  // expected-error {{invalid use of '__funcref' keyword outside the WebAssembly triple}}

int main() {
    return 0;
}
