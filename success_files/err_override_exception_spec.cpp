
namespace cwg126 {
  struct C {};
  struct D : C {};
  struct E : private C {};

#if __cplusplus <= 201402L
  struct A {
    virtual void cp() throw(C*);
    virtual void dp() throw(D*);
    virtual void ep() throw(E*); // expected-error {{exception specification of overriding function is more lax than base version}}
  };
  
  struct B : A {
    virtual void cp() throw(C*);
    virtual void dp() throw(D*);
    virtual void ep(); // For compilation errors related to expected-error
  };
#endif
}
