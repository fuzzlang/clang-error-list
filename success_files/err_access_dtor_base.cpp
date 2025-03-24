
class A {
    virtual ~A(); // private destructor
};

class B {};

class VeryDerivedC : public B, virtual public A {} vdc; // expected-error@#cwg7-C {{inherited virtual base class 'A' has private destructor}}
// expected-note@#cwg7-C {{in implicit destructor for 'VeryDerivedC' first required here}}
// expected-note@#cwg7-B {{declared private here}}

class X { 
    ~X(); // #cwg7-X
}; 

class Y : X { 
    ~Y() {}; 
}; 
