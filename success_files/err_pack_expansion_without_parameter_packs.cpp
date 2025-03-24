
namespace PR33082 {
  template<typename ...T> struct Pack {};

  void c() {
    int arr[] = {[](auto... v) {
      v; // expected-error {{unexpanded parameter pack 'v'}}
    }...}; // expected-error {{pack expansion does not contain any unexpanded parameter packs}}
  }
}
