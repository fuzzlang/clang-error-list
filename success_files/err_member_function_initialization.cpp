
class Base {
public:
    virtual int vf0() = 0l; // expected-error {{does not look like a pure-specifier}}
};
