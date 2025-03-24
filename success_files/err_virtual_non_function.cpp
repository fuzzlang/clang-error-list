
class Example {
public:
    virtual int viv; // expected-error {{'virtual' can only appear on non-static member functions}}
};
