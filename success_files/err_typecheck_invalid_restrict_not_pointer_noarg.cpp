
struct {
    typedef int *PtrToInt;
    friend __restrict PtrToInt; // expected-error {{'restrict' is invalid in friend declarations}} \
                                  // expected-error {{restrict requires a pointer or reference}}
} a;
