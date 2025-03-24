
struct G;

bool operator==(const G&, const G&); // expected-note {{previous declaration}}
bool operator!=(const G&, const G&); // expected-note {{previous declaration}}

struct G {
    friend bool operator==(const G&, const G&) = default; // expected-error {{because it was already declared outside}}
};
