
class Base {
public:
    virtual void h() = 0; // expected-error {{class member already marked 'abstract'}}
    virtual void h() abstract = 0; // expected-error {{class member already marked 'abstract'}}
};
