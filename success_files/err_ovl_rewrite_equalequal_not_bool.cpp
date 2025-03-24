
namespace not_bool {
  struct X {} x;
  struct Y {} y;
  double operator==(X, Y); // expected-note 4{{here}}
  bool a = x == y; // ok
  bool b = y == x; // expected-error {{return type 'double' of selected 'operator==' function for rewritten '==' comparison is not 'bool'}}
}
