
namespace ConversionOperatorDoesNotHaveDeducedReturnType {
  auto x = [](int){};
  auto y = [](auto &v) -> void { v.n = 0; }; // cxx03-cxx11-error {{'auto' not allowed in lambda parameter}} cxx03-cxx11-note {{candidate function not viable}} cxx03-cxx11-note {{conversion candidate}}
  using T = decltype(x);
  using U = decltype(y);
  using ExpectedTypeT = void (*)(int);
  template<typename T>
    using ExpectedTypeU = void (*)(T&);

  struct X {
#if __cplusplus > 201402L
    friend constexpr auto T::operator()(int) const; 
    friend constexpr T::operator ExpectedTypeT() const noexcept;

    template<typename T>
      friend constexpr void U::operator()(T&) const;
    template<typename T>
      friend constexpr U::operator ExpectedTypeU<T>() const noexcept;
#else
    friend auto T::operator()(int) const; // cxx11-error {{'auto' return without trailing return type; deduced return types are a C++14 extension}}
    friend T::operator ExpectedTypeT() const;

    template<typename T>
      friend void U::operator()(T&) const; // cxx03-cxx11-error {{friend declaration of 'operator()' does not match any declaration}}
    template<typename T>
      friend U::operator ExpectedTypeU<T>() const; // cxx03-cxx11-error {{friend declaration of 'operator void (*)(type-parameter-0-0 &)' does not match any declaration}}
#endif

  private:
    int n;
  };

  void use(X &x) {
    y(x); // cxx03-cxx11-error {{no matching function for call to object}}
  } 
}
