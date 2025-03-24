
namespace std {
  using size_t = decltype(sizeof(0));
  enum class align_val_t : size_t;

  struct destroying_delete_t {
    struct __construct { explicit __construct() = default; };
    explicit destroying_delete_t(__construct) {}
  };

  inline constexpr destroying_delete_t destroying_delete(destroying_delete_t::__construct());
}

template<typename T>
struct id_struct {
    using type = T;
};

template<typename T>
struct D {
    void operator delete(typename id_struct<D>::type *, std::destroying_delete_t); // expected-error {{use 'D<T> *'}}
};
