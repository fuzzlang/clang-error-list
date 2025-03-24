
struct bar {
    void func() {}
};

struct foo {
    bar operator->();  // expected-note 2 {{'->' applied to return value of the operator->() declared here}}
};

void test() {
    foo f;
    f->func();  // expected-error-re {{member reference type 'bar' is not a pointer{{$}}}}
}
