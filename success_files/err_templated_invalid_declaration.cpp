
struct S {
  template <typename Ty = char>
  static_assert(sizeof(Ty) != 1, "Not a char"); // expected-error {{a static_assert declaration cannot be a template}}
};

template <typename Ty = char>
static_assert(sizeof(Ty) != 1, "Not a char"); // expected-error {{a static_assert declaration cannot be a template}}
