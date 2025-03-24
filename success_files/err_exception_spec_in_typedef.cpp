
template<typename U>
using E = void(int n) throw(); // expected-error {{exception specifications are not allowed in type aliases}}

int main() {
    return 0;
}
