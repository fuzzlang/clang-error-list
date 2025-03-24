
template<typename T>
class X {
public:
    struct C { T &foo(); };
    
    struct D {
        struct E { T &bar(); }; // expected-error{{cannot form a reference to 'void'}}
        struct F; // expected-note{{member is declared here}}
    };
};

void test_instantiation(X<double>::C *x,
                        X<float>::D::E *e,
                        X<float>::D::F *f) {
    f->foo(); // expected-error{{implicit instantiation of undefined member 'X<float>::D::F'}}
}
