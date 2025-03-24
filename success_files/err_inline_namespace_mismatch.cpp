
namespace Std { // expected-note {{here}}
  typedef int Important;
}

inline namespace Std { // expected-error {{cannot be reopened as inline}}
  Important n;
}
