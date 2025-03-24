
struct S2 {
    struct S3 {};
};

struct S2::S3::public S2 { // expected-error{{'public' cannot be a part of nested name specifier; did you mean ':'?}}
};
