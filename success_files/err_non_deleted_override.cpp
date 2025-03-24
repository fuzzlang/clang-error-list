
class NoDestroy {
  ~NoDestroy(); 
};

struct A {
  virtual ~A();
};

struct B : public virtual A {
  NoDestroy x;
};

struct D : public virtual B {
  virtual void foo();
  ~D(); // expected-error {{non-deleted function '~D' cannot override a deleted function}}
};
