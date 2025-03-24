
namespace test {
  struct D {
    void operator delete(void*); // expected-note {{member 'operator delete' declared here}}
    void operator delete(void*, ...); // expected-note {{member 'operator delete' declared here}}
    virtual ~D();
  };
  
  D::~D() {} // expected-error {{multiple suitable 'operator delete' functions in 'D'}}
}
