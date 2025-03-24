
void func1(const char *, ...) __attribute__((__format__(printf, 1, 2))); // expected-error {{format attribute cannot specify the implicit this argument as the format string}}

class MyClass {
public:
    void method(const char *, ...) __attribute__((__format__(printf, 1, 2))); // expected-error {{format attribute cannot specify the implicit this argument as the format string}}
};
