
namespace N {
  void ::global_func(int) { } // expected-error{{definition or redeclaration of 'global_func' cannot name the global scope}}
}
