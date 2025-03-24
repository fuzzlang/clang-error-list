
namespace Q {
    const int N = 5;
}

template<int Q::N> struct C; // expected-error {{parameter declarator cannot be qualified}}

int main() {
    return 0;
}
