
enum e {};
bool operator==(e, int) = default; // expected-error{{expected class or reference to a constant class}}
