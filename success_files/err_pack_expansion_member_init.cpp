
template<typename T>
struct X {
    T member;

    X() : member()... { } // expected-error{{pack expansion for initialization of member 'member'}}
};
