
namespace ValidButUnsupported {
#if __cplusplus >= 201402L
  template<typename T> auto compute_linkage() {
    static int n;
    return &n;
  }

  typedef struct { // expected-error {{unsupported: anonymous type given name for linkage purposes by typedef declaration after its linkage was computed; add a tag name here to establish linkage}}
    struct X {};
    decltype(compute_linkage<X>()) a;
  } A; // expected-note {{by this typedef declaration}}
#endif
}
