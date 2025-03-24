
namespace std {
  struct strong_ordering {
    int n;
    constexpr operator int() const { return n; }
    static const strong_ordering less, equal, greater;
  };
  constexpr strong_ordering strong_ordering::less = {-1};
  constexpr strong_ordering strong_ordering::equal = {0};
  constexpr strong_ordering strong_ordering::greater = {1};
}

namespace DeleteAfterFirstDecl {
  bool operator==(const struct Q&, const struct Q&);
  struct Q {
    struct X {
      friend std::strong_ordering operator<=>(const X&, const X&);
    } x; 
    // expected-error@+1 {{defaulting the corresponding implicit 'operator==' for this defaulted 'operator<=>' would delete it after its first declaration}}
    friend std::strong_ordering operator<=>(const Q&, const Q&) = default;
  };
}
