
template<typename T>
auto f1();

int main() {
    auto (*p)() = f1; // expected-error {{variable 'p' with type 'auto (*)()' has incompatible initializer of type '<overloaded function type>'}}
    return 0;
}
