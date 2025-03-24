
namespace std {
template <typename T> struct remove_reference { using type = T; };
template <typename T> struct remove_reference<T &> { using type = T; };
template <typename T> struct remove_reference<T &&> { using type = T; };
template <typename T>
constexpr typename std::remove_reference<T>::type&& move(T &&t) noexcept {
  return static_cast<typename std::remove_reference<T>::type &&>(t);
}
}

namespace Move {
#if __cplusplus >= 202002L
  consteval int f_eval() { // both-note {{declared here}}
    return 0;
  }

  struct Copy {
    int(*ptr)();
    constexpr Copy(int(*p)() = nullptr) : ptr(p) {}
    consteval Copy(const Copy&) = default;
  };

  constexpr const Copy &to_lvalue_ref(const Copy &&a) {
    return a;
  }

  void test() {
    { Copy c(std::move(Copy(&f_eval))); } // both-error {{is not a constant expression}} \
                                          // both-note {{to a consteval}}
  }
#endif
}
