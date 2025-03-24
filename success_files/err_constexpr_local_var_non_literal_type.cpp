
struct NonLiteral { // beforecxx23-note 2{{no constexpr constructors}}
    NonLiteral() {}
    NonLiteral(int) {}
};

constexpr int DisallowedStmtsCXX14_4() {
    return 0;
    NonLiteral nl; // beforecxx23-error {{variable of non-literal type 'NonLiteral' cannot be defined in a constexpr function before C++23}} \
}
