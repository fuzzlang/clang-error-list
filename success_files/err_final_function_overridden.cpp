
class Base {
public:
    virtual void SealedFunction() final; // final function
};

class Derived : public Base {
public:
    // expected-error@+2 {{declaration of 'SealedFunction' overrides a 'sealed' function}}
    // expected-warning {{'SealedFunction' overrides a member function but is not marked 'override'}}
    virtual void SealedFunction(); 
};
