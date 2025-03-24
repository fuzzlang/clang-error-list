
typedef int INT;

class B {
public:
    int m;

    B() : m(1), INT(17) { // expected-error{{constructor initializer 'INT' (aka 'int') does not name a class}}
    }
};
