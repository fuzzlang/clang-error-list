
struct S1; // expected-note {{declared here}}
extern S1 a;

class S2 {
    mutable int a;
    S2 &operator+(const S2 &arg) { return (*this); } // expected-note {{implicitly declared private here}}
public:
    S2() : a(0) {}
};

const S2 b; // const-qualified variable
class S3 {
    int a;
public:
    int b;
    S3() : a(0) {}
};

S3 c;               // expected-note {{'c' defined here}}
const S3 ca[5];     // expected-note {{'ca' defined here}}

extern const int f; // expected-note {{'f' declared here}}

void foo() {
    #pragma omp distribute parallel for reduction(+ : a, b, c, f) // expected-error {{a reduction list item with incomplete type 'S1'}} expected-error 3 {{const-qualified variable cannot be reduction}} expected-error 2 {{'operator+' is a private member of 'S2'}} expected-warning 2 {{type 'S2' is not trivially copyable and not guaranteed to be mapped correctly}} expected-warning 2 {{type 'S3' is not trivially copyable and not guaranteed to be mapped correctly}}
    for (int i = 0; i < 10; ++i) {
        // loop body
    }
}
