
namespace StackUseAfterScope {
template <typename T> class Bar {};
class Foo {
  template <> friend class Bar<int>; // expected-error {{template specialization declaration cannot be a friend}}
  bool aux;
};
}
