
class A { };

class B1 : A { };

class B2 : virtual A { };

class B3 : virtual virtual A { }; // expected-error{{duplicate 'virtual' in base specifier}}

class C : public B1, private B2 { };

class D;                // expected-note {{forward declaration of 'D'}}
class E : public D { }; // expected-error{{base class has incomplete type}}

typedef int I;

class F : public I { }; // expected-error{{base specifier must name a class}}

union U1 : public A { }; // expected-error{{unions cannot have base classes}}

union U2 {};

class G : public U2 { }; // expected-error{{unions cannot be base classes}}
