
namespace std {
  struct strong_ordering { // both-note 6{{candidate}}
    int n;
    constexpr operator int() const { return n; }
    static const strong_ordering less, equal, greater;
  };
  constexpr strong_ordering strong_ordering::less{-1},
      strong_ordering::equal{0}, strong_ordering::greater{1};

  struct weak_ordering {
    int n;
    constexpr weak_ordering(int n) : n(n) {}
    constexpr weak_ordering(strong_ordering o) : n(o.n) {}
    constexpr operator int() const { return n; }
    static const weak_ordering less, equivalent, greater;
  };
  constexpr weak_ordering weak_ordering::less{-1},
      weak_ordering::equivalent{0}, weak_ordering::greater{1};

  struct partial_ordering {
    double d;
    constexpr partial_ordering(double d) : d(d) {}
    constexpr partial_ordering(strong_ordering o) : d(o.n) {}
    constexpr partial_ordering(weak_ordering o) : d(o.n) {}
    constexpr operator double() const { return d; }
    static const partial_ordering less, equivalent, greater, unordered;
  };
  constexpr partial_ordering partial_ordering::less{-1},
      partial_ordering::equivalent{0}, partial_ordering::greater{1},
      partial_ordering::unordered{__builtin_nan("")};

  static_assert(!(partial_ordering::unordered < 0));
  static_assert(!(partial_ordering::unordered == 0));
  static_assert(!(partial_ordering::unordered > 0));
}

namespace Deletedness {
  struct A {
    std::strong_ordering operator<=>(const A&) const;
  };
  struct B {
    bool operator==(const B&) const;
    bool operator<(const B&) const;
  };
  struct C {
    std::strong_ordering operator<=>(const C&) const = delete; // both-note 2{{deleted}}
  };
  struct D1 {
    bool operator==(const D1&) const;
    std::strong_ordering operator<=>(int) const; // both-note 2{{function not viable}} both-note 2{{function (with reversed parameter order) not viable}}
    bool operator<(int) const; // both-note 2{{function not viable}}
  };
  struct D2 {
    bool operator<(const D2&) const;
    std::strong_ordering operator<=>(int) const; // both-note 2{{function not viable}} both-note 2{{function (with reversed parameter order) not viable}}
    bool operator==(int) const; // both-note 2{{function not viable}}
  };
  struct E {
    bool operator==(const E&) const;
    bool operator<(const E&) const = delete; // both-note 2{{deleted}}
  };
  struct F {
    std::strong_ordering operator<=>(const F&) const; // both-note 2{{candidate}}
    std::strong_ordering operator<=>(F) const; // both-note 2{{candidate}}
  };
  struct G1 {
    bool operator==(const G1&) const;
    void operator<(const G1&) const;
  };
  struct G2 {
    void operator==(const G2&) const;
    bool operator<(const G2&) const;
  };
  struct H {
    void operator<=>(const H&) const;
  };

  template<typename T> struct Cmp : T { // #base
    std::strong_ordering operator<=>(const Cmp&) const = default; // #cmp both-note 5{{here}}
  };

  void use(...);
  void f() {
    use(
      Cmp<A>() <=> Cmp<A>(),
      Cmp<B>() <=> Cmp<B>(),
      Cmp<C>() <=> Cmp<C>() // both-error {{deleted}}
    );    
  }
}
