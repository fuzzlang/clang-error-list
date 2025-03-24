
template<typename T, int Subscript1, int Subscript2, typename Val1, typename Val2>
struct DesigArrayInit0 {
  void f(Val1 val1, Val2 val2) {
    T array = {
      [Subscript1] = static_cast<int>(val1),
      [Subscript2] = val2 // expected-error{{exceeds array bounds}}
    };
  }
};

template struct DesigArrayInit0<int[8], 5, 13, float, int>; // expected-note{{instantiation}}
