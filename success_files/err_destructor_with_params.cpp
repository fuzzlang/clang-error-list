
struct S {
    ~S(this S) {} // expected-error {{an explicit object parameter cannot appear in a destructor}}
};
