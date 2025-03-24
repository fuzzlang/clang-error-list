
namespace NonClass {
    typedef int type;
    struct hiding {};
    int hiding;
}

class Test0 {
    using NonClass::type; // expected-error {{not a class}}
};
