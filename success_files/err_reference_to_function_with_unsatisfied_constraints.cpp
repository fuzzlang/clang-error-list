
template <typename T>
struct ChecksMemberVar {
    T t;
    void foo() requires (false) {} // #CMV_FOO
    template <typename U>
    void foo2() requires (true) {} // #CMV_FOO2
};

void test() {
    ChecksMemberVar<int> CMV;
    CMV.foo();
    CMV.foo2<int>();
    
    ChecksMemberVar<float> CMV2;
    CMV2.foo(); // expected-error{{invalid reference to function 'foo'}}
    // expected-note@#CMV_FOO{{because 'IsInt<decltype(this->t)>' evaluated to false}}
    CMV2.foo2<float>();
}
