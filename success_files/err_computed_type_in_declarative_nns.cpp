
struct D {};

struct C {} decltype(D())::c; // expected-error {{a 'decltype' specifier cannot be used in a declarative nested name specifier}}
