
class __declspec(dllexport) ClassWithMultipleDefaultCtors {
public:
    ClassWithMultipleDefaultCtors(int = 40) {} // expected-error{{'__declspec(dllexport)' cannot be applied to more than one default constructor}}
    ClassWithMultipleDefaultCtors(double = 3.14) {}
};
