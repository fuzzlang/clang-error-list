
enum X : int { e };
#if defined(CXX11)
#error "enumeration types with a fixed underlying type are incompatible with C++98"
#elif defined(CXX03)
#error "enumeration types with a fixed underlying type are a C++11 extension"
#elif defined(OBJC) || defined(C23)
#else
#error "enumeration types with a fixed underlying type are a Clang extension"
#endif

// Don't warn about the forward declaration in any language mode.
enum Fwd : int;
enum Fwd : int { e2 };
#if !defined(OBJC) && !defined(C23)
#error "enumeration types with a fixed underlying type"
#error "enumeration types with a fixed underlying type"
#endif

// Always error on the incompatible redeclaration.
enum BadFwd : int;
#if !defined(OBJC) && !defined(C23)
#error "enumeration types with a fixed underlying type"
#endif
// expected-note@-4 {{previous declaration is here}}
enum BadFwd : char { e3 };
