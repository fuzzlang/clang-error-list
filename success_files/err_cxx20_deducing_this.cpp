
constexpr int f(int n) {  // expected-error {{constexpr function never produces a constant expression}}
  static const int m = n; // note {{control flows through the definition of a static variable}} 
  return m;
}

static_assert(f(0) == 0, ""); // expected-error {{not an integral constant expression}} 

constexpr int g(int n) {        // expected-error {{constexpr function never produces a constant expression}}
  thread_local const int m = n; // note {{control flows through the definition of a thread_local variable}} 
  return m;
}

static_assert(g(0) == 0, ""); // expected-error {{not an integral constant expression}} 

constexpr int c_thread_local(int n) { // expected-error {{constexpr function never produces a constant expression}}
  static _Thread_local int m = 0;     // note {{control flows through the definition of a thread_local variable}} 
  return m;
}

static_assert(c_thread_local(0) == 0, ""); // expected-error {{not an integral constant expression}} 

constexpr int gnu_thread_local(int n) { // expected-error {{constexpr function never produces a constant expression}}
  static __thread int m = 0;            // note {{control flows through the definition of a thread_local variable}} 
  return m;
}

static_assert(gnu_thread_local(0) == 0, ""); // expected-error {{not an integral constant expression}} 

constexpr int h(int n) {  // expected-error {{constexpr function never produces a constant expression}}
  static const int m = n; // note {{control flows through the definition of a static variable}} 
  return &m - &m;
}

constexpr int i(int n) {        // expected-error {{constexpr function never produces a constant expression}}
  thread_local const int m = n; // note {{control flows through the definition of a thread_local variable}} 
  return &m - &m;
}

constexpr int j(int n) {
  if (!n)
    return 0;
  static const int m = n; 
  return m;
}
constexpr int j0 = j(0);

constexpr int k(int n) {
  if (!n)
    return 0;
  thread_local const int m = n; 
  return m;
}
constexpr int k0 = k(0);

namespace StaticLambdas {
  constexpr auto static_capture_constexpr() {
    char n = 'n';
    return [n] static { return n; }(); // expected-error {{a static lambda cannot have any captures}} 
  }
  static_assert(static_capture_constexpr()); // expected-error {{static assertion expression is not an integral constant expression}} 

  constexpr auto capture_constexpr() {
    char n = 'n';
    return [n] { return n; }();
  }
  static_assert(capture_constexpr());
}

namespace StaticOperators {
  auto lstatic = []() static { return 3; };  
  static_assert(lstatic() == 3, "");
  constexpr int (*f2)(void) = lstatic;
  static_assert(f2() == 3);
  
  struct S1 {
    constexpr S1() { // expected-error {{never produces a constant expression}}
      throw; // note {{not valid in a constant expression}} 
    }
    static constexpr int operator()() { return 3; } 
  };
  static_assert(S1{}() == 3, ""); // expected-error {{not an integral constant expression}} 
}

int test_in_lambdas() {
  auto c = [](int n) constexpr {
    if (n == 0)
      return 0;
    else
      goto test; 
  test:
    return 1;
  };
  c(0);
  constexpr auto A = c(1); // expected-error {{must be initialized by a constant expression}} 
  return 0;
}

template <auto... p>
struct check_ice {
    enum e {
        x = p...[0] // expected-warning {{is a C++2c extension}}
    };
};
static_assert(check_ice<42>::x == 42);

namespace VirtualBases {
  namespace One {
    struct U { int n; };
    struct V : U { int n; };
    struct A : virtual V { int n; };
    struct Aa { int n; };
    struct B : virtual A, Aa {};
    struct C : virtual A, Aa {};
    struct D : B, C {};

    /// Calls the constructor of D.
    D d;
  }
}

namespace LabelGoto {
  constexpr int foo() { // expected-error {{never produces a constant expression}}
    a: // expected-warning {{use of this statement in a constexpr function is a C++23 extension}}
    goto a; // note {{subexpression not valid in a constant expression}} 
    return 1;
  }
  static_assert(foo() == 1, ""); // expected-error {{not an integral constant expression}} 
}

namespace ExplicitLambdaThis {
  constexpr auto f = [x = 3]<typename Self>(this Self self) { // expected-error {{explicit object parameters are incompatible with C++ standards before C++2b}}

