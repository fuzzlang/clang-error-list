
namespace union_ {
  union U { int a, b; };
  U u = {
    .a = 1, // override-note {{here}}
    .b = 2, // override-error {{overrides prior}}
  };

  void test() {
    union U d = {.x = 1, .y = 2}; // expected-error {{'x' does not refer to any field}}
  }
}
