
struct S1 {
  template<typename T> concept C1 = true; // expected-error {{concept declarations may only appear in global or namespace scope}}
};
