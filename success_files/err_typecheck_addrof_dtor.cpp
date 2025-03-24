
struct A {
    ~A();
};

int main() {
    auto p = &A::~A; // expected-error{{taking the address of a destructor}}
    return 0;
}
