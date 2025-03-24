
namespace diag {

template <typename T> requires true // expected-note{{previous template declaration is here}}
struct A;

template <typename T> struct A; // expected-error{{requires clause differs in template redeclaration}}

template <typename T> struct B; // expected-note{{previous template declaration is here}}
template <typename T> requires true // expected-error{{requires clause differs in template redeclaration}}
struct B;

template <typename T> requires true // expected-note{{previous template declaration is here}}
struct C;
template <typename T> requires (!0) // expected-error{{requires clause differs in template redeclaration}}
struct C;

template<typename T>
concept C1 = true;

template <C1 T> // expected-note{{previous template declaration is here}}
struct D;
template <typename T> requires C1<T> // expected-error{{type constraint differs in template redeclaration}}
struct D;

} // end namespace diag
