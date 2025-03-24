
int (*a)() = nullptr;
int (*b)() = nullptr;

auto tw0 = a <=> b; // expected-error {{ordered comparison of function pointers}}
