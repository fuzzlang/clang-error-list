
class MyClass {
    using namespace A; // expected-error {{'using namespace' is not allowed in classes}}
    
public:
    void myFunction() {}
};
