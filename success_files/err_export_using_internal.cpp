
export module p5;

int a; // expected-note {{target}}
static int sa; // expected-note {{target}}
void b(); // expected-note {{target}}
static void sb(); // expected-note {{target}}
struct c {}; // expected-note {{target}}
enum d {}; // expected-note {{target}}
using e = int;
using f = c;
static union { int sg1, sg2; }; // expected-note {{target}}
namespace NS {}

export {
  using ::a; // expected-error {{using declaration referring to 'a' with module linkage cannot be exported}}
}
