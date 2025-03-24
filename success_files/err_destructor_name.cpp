
struct rdar9677163 {
    struct Y { ~Y(); }; // expected-error{{non-friend class member '~Y' cannot have a qualified name}}
    struct Z { ~Z(); }; 
    ~Z(); // expected-error{{expected the class name after '~' to name the enclosing class}}
};
