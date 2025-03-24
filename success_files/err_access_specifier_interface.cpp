
__interface I1 {
protected: // expected-error {{interface types cannot specify 'protected' access}}
    virtual void fn() = 0;
};
