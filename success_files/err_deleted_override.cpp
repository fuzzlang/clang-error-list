
struct X10 {
  virtual ~X10();
};

struct X11 : X10 { // expected-error{{deleted function '~X11' cannot override a non-deleted function}}
  void operator delete(void*, int); // expected-note{{'operator delete' declared here}}
};
