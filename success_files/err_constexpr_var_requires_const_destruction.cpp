
namespace ConstThis {
  class FooDtor {
    int a;
  public:
    constexpr FooDtor() {
      this->a = 10;
    }
    constexpr ~FooDtor() {
      this->a = 12;
    }
  };

  constexpr int foo() {
    const FooDtor f;
    return 0;
  }
  
  template <bool Good>
  struct dtor_test {
    int a = 0;

    constexpr dtor_test() = default;
    constexpr ~dtor_test() {
      if (Good)
        a = 10;
      int local = 100 / a; // both-note {{division by zero}}
    }
  };

  constexpr dtor_test<false> bad_dtor; // both-error {{must have constant destruction}} \
                                       // both-note {{in call to}}
}
