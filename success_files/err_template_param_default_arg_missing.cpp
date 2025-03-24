
// expected-error@-1 {{cannot add a default template argument to the definition of a member of a class template}}

template<typename> void friend_h();
struct A {
    // FIXME: This is ill-formed.
    template<typename=void> struct friend_B;
    // FIXME: f, h, and i are ill-formed.
    //  f is ill-formed because it is not a definition.
    //  h and i are ill-formed because they are not the only declarations of the
    //  function in the translation unit.
    template<typename=void> void friend_f();
    // cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
    template<typename=void> void friend_g() {}
    // cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
    template<typename=void> void friend_h() {}
    // cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
    template<typename=void> void friend_i() {}
    // cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
};
template<typename> void friend_i();

template<typename=void, typename X> void foo(X) {}
// cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
template<typename=void, typename X> struct Foo {};
