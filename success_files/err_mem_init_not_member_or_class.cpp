
struct Wrong {
    Wrong() : NonExistent() {} // expected-error {{member initializer 'NonExistent' does not name a non-static data member or base class}}
};
