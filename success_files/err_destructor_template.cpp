
class A {
public:
    template<int>
    friend A::~A(); // expected-error {{destructor cannot be declared as a template}}
    
    ~A() {}
};
