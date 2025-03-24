
struct Example {
    Example(this auto param) { // expected-error {{an explicit object parameter cannot appear in a constructor}}
    }
};
