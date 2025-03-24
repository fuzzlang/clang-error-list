
namespace GH69233 {
struct Base {};
struct Thing {
    Thing(this Self&& self, int args) { } // expected-error {{an explicit object parameter cannot appear in a constructor}}
};

struct S : Base {
    int j;
    S& operator=(this Base& self, const S&) = default;
    // expected-warning@-1 {{explicitly defaulted copy assignment operator is implicitly deleted}}
    // expected-note@-2 {{function is implicitly deleted because its declared type does not match the type of an implicit copy assignment operator}}
    // expected-note@-3 {{explicitly defaulted function was implicitly deleted here}}
};

struct S2 {
    S2& operator=(this int&& self, const S2&);
    S2& operator=(this int&& self, S2&&);
    operator int();
};

S2& S2::operator=(this int&& self, const S2&) = default; // expected-warning {{explicitly defaulted copy assignment operator is implicitly deleted}}
}
