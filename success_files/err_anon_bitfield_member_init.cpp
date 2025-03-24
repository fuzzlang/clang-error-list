
namespace cwg1966 { // cwg1966: 11
#if __cplusplus >= 201103L
  struct Q {
    enum X : enum Y : int {} {}; // since-cxx11-error@-1 {{'cwg1966::Y' cannot be defined in a type specifier}}
  };
#endif
}
