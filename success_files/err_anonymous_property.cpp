
struct StructWithUnnamedMember {
  __declspec(property(get=GetV)) int : 10; // expected-error {{anonymous property is not supported}}
  
  int GetV() { return 123; } // Necessary for completeness
};
