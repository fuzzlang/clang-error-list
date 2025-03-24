
class MyClass {
public:
    void operator++(char) {} // expected-error{{parameter of overloaded post-increment operator must have type 'int' (not 'char')}}
};

int main() {
    MyClass obj;
    obj++;
    return 0;
}
