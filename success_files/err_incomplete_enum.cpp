
namespace Stuart {
    enum C; // Forward declaration of enum C
}

using enum Stuart::C; // expected-error{{is incomplete}}

int main() {
    return 0;
}
