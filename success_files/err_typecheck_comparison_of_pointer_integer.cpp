
struct Base {};
constexpr Base *nullB1 = nullptr;
static_assert(nullB1 == (1 - 1), ""); // expected-error {{comparison between pointer and integer}}
