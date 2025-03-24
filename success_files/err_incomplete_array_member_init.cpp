
namespace ex7 {
struct S {
  int a;
  const char* b;
  int c;
  int d = b[a];
};

constexpr S ss = { 1, "example" };
static_assert(ss.a == 1);
static_assert(__builtin_strcmp(ss.b, "example") == 0);
static_assert(ss.c == int{});
static_assert(ss.d == ss.b[ss.a]);

struct base {
  int x = 5;
  int y[] = { 1 }; // expected-error@-1 {{type 'int' cannot be narrowed to 'int' in initializer list}}
};

struct derived : base {
  int z;
};

constexpr derived d = {{}, 10}; // This line will cause an error
static_assert(d.x == 5);
static_assert(d.z == 10);
} // namespace ex7
