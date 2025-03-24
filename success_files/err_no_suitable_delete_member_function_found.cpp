
// expected-error@-1 {{no suitable member 'operator delete' in 'D'}}
//   expected-note@#cwg252-D {{member 'operator delete' declared here}}

struct D {
    void operator delete(void*, int); // #cwg252-D
    virtual ~D();
};

D::~D() {}
