
namespace ExceptionSpecification {
  struct Nested {
    struct T {
      T() noexcept(!noexcept(Nested())); // expected-note {{in evaluation of exception spec}}
    } t; // expected-error{{exception specification is not available until end of class definition}}
  };
}
