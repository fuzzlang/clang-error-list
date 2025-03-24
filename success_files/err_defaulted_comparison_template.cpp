
struct B {};

template<typename T = void>
bool operator<(const B&, const B&) = default; // expected-error {{comparison operator template cannot be defaulted}}
