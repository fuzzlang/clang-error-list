
class Abstract {
public:
    virtual void func() = 0; // pure virtual function
};

class Derived1 : public Abstract {
public:
    void func() override {}
};

class Derived2 : public Abstract {
public:
    void func() override {}
};

int main() {
    const Abstract &abstract1 = true ? static_cast<const Abstract&>(Derived1()) : Derived2(); // expected-error {{allocating an object of abstract class type 'const Abstract'}}
    return 0;
}
