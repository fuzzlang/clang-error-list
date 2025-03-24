
namespace N { struct X { }; };

namespace A = N;

int B; // expected-note {{previous definition is here}}
namespace B = N; // expected-error {{redefinition of 'B' as different kind of symbol}}

namespace H {
    namespace A1 { }
    namespace A2 { }

    namespace B = A1;
    namespace B = A1; // expected-note {{previously defined as an alias for 'A1'}}
    namespace C = B;
    namespace B = C; // expected-note {{previously defined as an alias for 'A1'}}
    
    namespace B = A2; // expected-error {{redefinition of 'B' as an alias for a different namespace}}
}
