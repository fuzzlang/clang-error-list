
template<typename T, typename... Args, typename = int> // expected-error{{template parameter pack must be the last template parameter}}
class MyClass {
public:
    MyClass() {}
};
