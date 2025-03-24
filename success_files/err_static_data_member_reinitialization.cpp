
namespace cwg89 { // cwg89: class member redeclaration
  template<typename T> struct A {
    static int value; // #cwg89-value
  };

  // expected-error@-1 {{class member cannot be redeclared}}
  // expected-note@#cwg89-note {{previous declaration is here}}
  template<typename T> struct A { // Redeclaration of static member 
    static int value; // redeclaration of 'value'
  };
}

// cwg90: dup 447

namespace cwg91 { // cwg91: no
  template<typename U> struct B {};
  // FIXME: This is invalid.
  B<void() throw()> b; // invalid usage
  // This is valid under certain circumstances.
  B<void(void() throw())> c;
}

namespace cwg92 { // cwg92: static member initialization
  template<typename T> struct C {
    static const char d = 'A'; // #cwg92-d
    static const char e;
  };

  // expected-error@-1 {{class member cannot be redeclared}}
  // expected-note@#cwg92-note {{previous declaration is here}}
  template<> const char C<int>::d = 'B'; // redeclaration of static member
}
