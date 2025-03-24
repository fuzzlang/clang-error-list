
namespace GH60518 {
struct StringLiteral {
template <int N>
StringLiteral(const char (&array)[N])
    __attribute__((enable_if(__builtin_strlen(array) == 2, // cxx03-error {{'enable_if' attribute expression never produces a constant expression}} cxx03-note {{read of variable 'array' not allowed in a constant expression}}
                              "invalid string literal")));
};

void test() {
    StringLiteral sl("xx"); // Should produce the enable_if error as intended.
}
}
