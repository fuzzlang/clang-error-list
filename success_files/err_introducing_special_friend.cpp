
class MyClass {
public:
    friend operator bool() const; // expected-error {{must use a qualified name when declaring a conversion operator as a friend}}
};
