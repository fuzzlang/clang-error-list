
struct {
  int friend; // expected-error {{'friend' must appear first in a non-function declaration}}
} a;
