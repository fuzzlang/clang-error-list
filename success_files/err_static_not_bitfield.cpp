
namespace bitfield {
struct S {
  template <int I>
  static int f : I; // expected-error {{static member 'f' cannot be a bit-field}}
};
}
