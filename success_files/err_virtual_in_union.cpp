
union U {
    int d;
    virtual int f() { return d; } // expected-error {{unions cannot have virtual functions}}
};
