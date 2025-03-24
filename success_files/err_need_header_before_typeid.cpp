
struct Indestructible {
    Indestructible() = delete;
};

int main() {
    typeid(Indestructible{}); // expected-error {{deleted}} expected-error {{you need to include <typeinfo>}}
    return 0;
}
