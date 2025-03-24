
@interface Super @end
@interface Sub : Super @end

void f2(void(^f)(Super *)) { // expected-note{{passing argument to parameter 'f' here}}
    Super *o;
    f(o);
}

void f3(void(^f)(Sub *)) {
    Sub *o;
    f(o);
}

void test1(void) {
    f2(^(Sub *o) { });    // expected-error {{incompatible block pointer types passing}}
    f3(^(Super *o) { });  // OK
}
