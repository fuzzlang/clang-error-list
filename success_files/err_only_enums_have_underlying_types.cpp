
template<typename T, typename U>
struct is_same_type {
  static const bool value = false;
};

template <typename T>
struct is_same_type<T, T> {
  static const bool value = true;
};

__underlying_type(int) a; // expected-error {{only enumeration types}}
__underlying_type(struct b) c; // expected-error {{only enumeration types}}
