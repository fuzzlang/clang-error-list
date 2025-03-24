
namespace N {
  typedef char C;
}

namespace M {
  typedef double D;
}

struct NonLiteral { 
  NonLiteral() {}
  NonLiteral(int) {}
};

struct S {
  virtual int ImplicitlyVirtual() const = 0; 
};

struct SS : S {
  int ImplicitlyVirtual() const;
};

struct T : SS, NonLiteral {
  constexpr T();
  constexpr int f() const;

  virtual constexpr int ExplicitlyVirtual() const { return 0; } // beforecxx20-error {{virtual function cannot be constexpr}}
  constexpr int ImplicitlyVirtual() const { return 0; } // beforecxx20-error {{virtual function cannot be constexpr}}
  virtual constexpr int OutOfLineVirtual() const; // beforecxx20-error {{virtual function cannot be constexpr}}

  constexpr NonLiteral NonLiteralReturn() const { return {}; } // beforecxx23-error {{constexpr function's return type 'NonLiteral' is not a literal type}}
  constexpr void VoidReturn() const { return; } // beforecxx14-error {{constexpr function's return type 'void' is not a literal type}}
  constexpr ~T(); // beforecxx20-error {{destructor cannot be declared constexpr}}

  typedef NonLiteral F() const;
  constexpr F NonLiteralReturn2; 

  constexpr int NonLiteralParam(NonLiteral) const { return 0; } // beforecxx23-error {{constexpr function's 1st parameter type 'NonLiteral' is not a literal type}}
  typedef int G(NonLiteral) const;
  constexpr G NonLiteralParam2; 

  constexpr int Deleted() const = delete;
  constexpr T &operator=(const T &) = default; // beforecxx14-error {{an explicitly-defaulted copy assignment operator may not have 'const', 'constexpr' or 'volatile' qualifiers}}
};
