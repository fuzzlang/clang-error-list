
namespace test_conversion {

struct D {
  D(); // Default constructor
  D(D &&) = delete; // Delete move constructor
};

D test2(D x) { return x; } // expected-error {{invokes a deleted function}}

} // namespace test_conversion

namespace test_simpler_implicit_move {

struct CopyOnly {
  CopyOnly(); // cxx23-note {{candidate constructor not viable: requires 0 arguments, but 1 was provided}}
  CopyOnly(CopyOnly &); // cxx23-note {{candidate constructor not viable: expects an lvalue for 1st argument}}
};

struct MoveOnly {
  MoveOnly();
  MoveOnly(MoveOnly &&);
};

MoveOnly &&rref();

MoveOnly &&test1(MoveOnly &&w) {
  return w; // cxx98_20-error {{cannot bind to lvalue of type}}
}

} // namespace test_simpler_implicit_move
