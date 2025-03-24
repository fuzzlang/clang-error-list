
#define _diagnose_if(...) __attribute__((diagnose_if(__VA_ARGS__)))

using size_t = decltype(sizeof(int));

namespace type_dependent {
template <typename T>
void neverok() _diagnose_if(!T(), "oh no", "error") {} // expected-note 4{{from 'diagnose_if'}}
  
void runAll() {
    neverok<int>(); // expected-error{{oh no}}
}
}
