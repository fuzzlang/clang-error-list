
// expected-error@-2 {{'auto' deduced as 'int *' in declaration of 'z' and deduced as 'int' in declaration of 'q'}}
#if __cplusplus >= 201103L
  auto z = 5, q = {1, 2};
  // since-cxx11-error@-1 {{'auto' deduced as 'int' in declaration of 'z' and deduced as 'std::initializer_list<int>' in declaration of 'q'}}
  auto (*funcPtr)(int) -> int, j = 0;
  // since-cxx11-error@-1 {{declaration with trailing return type must be the only declaration in its group}}
#endif
}

namespace example { // A sample namespace
#if __cplusplus >= 201103L
struct noexceptConstructor {
  noexceptConstructor(int) noexcept {}
};

struct throwingStruct : noexceptConstructor {
  int b = []() noexcept(false) { return 1; }();
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(throwingStruct, int), "");

struct throwingConstructor {
  throwingConstructor() noexcept(false) {}
};

struct throwingNested : noexceptConstructor {
  throwingConstructor d;
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(throwingNested, int), "");

struct throwingTemplateConstructor {
  template <typename = int>
  throwingTemplateConstructor() noexcept(false) {}
};

struct throwingNestedTemplate : noexceptConstructor {
  throwingTemplateConstructor e;
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(throwingNestedTemplate, int), "");

struct D1 : noexceptConstructor, throwingConstructor {
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(D1, int), "");

struct D2 : noexceptConstructor, throwingTemplateConstructor {
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(D2, int), "");

struct defaultArgThrowing {
  defaultArgThrowing(throwingConstructor = {}) {}
};

struct D3 : noexceptConstructor, defaultArgThrowing {
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(D3, int), "");

struct defaultArgThrowingTemplate {
  template <typename = int>
  defaultArgThrowingTemplate(throwingConstructor = {}) {}
};

struct D4 : noexceptConstructor, defaultArgThrowingTemplate {
  using noexceptConstructor::noexceptConstructor;
};

static_assert(!__is_nothrow_constructible(D4, int), "");
#endif
} // namespace example

namespace anotherExample { // Another sample namespace
struct A {
#if __cplusplus >= 201103L
  int c = sizeof(A);
#endif
  void h(int d = sizeof(A));
};

template <typename T>
struct B {
#if __cplusplus >= 201103L
  int f = sizeof(B) + sizeof(T);
#endif
  void h(int d = sizeof(B) + sizeof(T));
};

template class B<int>;
} // namespace anotherExample

namespace yetAnotherExample { // Yet another sample namespace
#if __cplusplus >= 201103L
  struct Literal { constexpr operator int() const { return 0; } };
  struct NonLiteral { NonLiteral(); operator int(); }; 
  struct NonConstexprConversion { constexpr operator int() const; };
  struct Virtual { virtual int g(int) const; };

  template<typename X, typename Y, typename Z> struct A : Z {
    int member;
    constexpr A(Y y) : member(y) {}
    constexpr X g(Y y) const { return X(); }
  };

  constexpr A<Literal, Literal, Literal> ce = Literal();
  constexpr int x = ce.g(Literal{});

  A<NonLiteral, NonLiteral, Virtual> b = NonLiteral();
  void f() { b.g(NonLiteral()); }

  // Constructor is still constexpr, so this is a literal type.
  static_assert(__is_literal_type(decltype(b)), "");

  // Constructor can call non-constexpr functions.
  A<Literal, NonConstexprConversion, Literal> c = NonConstexprConversion();

  struct B : Virtual {
    int member;
    constexpr B(NonLiteral y) : member(y) {}
