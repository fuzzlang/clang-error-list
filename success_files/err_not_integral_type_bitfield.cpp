
class C {
public:
    typedef int func(); 
    func btm : 1; // expected-error {{bit-field 'btm' has non-integral type}}
};
