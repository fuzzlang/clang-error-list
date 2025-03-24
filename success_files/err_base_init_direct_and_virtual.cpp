
class A {
  int m;
public:
   A() : A::m(17) { } // expected-error {{member initializer 'm' does not name a non-static data member or base class}}
   A(int);
};

class B : public A {
public:
  B() : A(), m(1), n(3.14) { }

private:
  int m;
  float n;
};

class C : public virtual B {
public:
  C() : B() { }
};

class D : public C {
public:
  D() : B(), C() { }
};

class E : public D, public B {  // expected-warning{{direct base 'B' is inaccessible due to ambiguity:\\n    class E -> D -> C -> B\\n    class E -> B}}
public:
  E() : B(), D() { } // expected-error{{base class initializer 'B' names both a direct base class and an inherited virtual base class}}
};
