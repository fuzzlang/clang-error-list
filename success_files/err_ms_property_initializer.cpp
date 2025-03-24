
struct StructWithProperty {
  __declspec(property(get=GetV)) int V13 = 3; // expected-error {{property declaration cannot have a default member initializer}}
  
  int GetV() { return 123; }
  void SetV(int v) {}
};
