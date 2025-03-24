
struct Errors {
    using __super::foo; // expected-error {{'__super' cannot be used with a using declaration}}
    __super::XXX x; // expected-error {{invalid use of '__super', Errors has no base classes}} expected-error {{expected}}
};
