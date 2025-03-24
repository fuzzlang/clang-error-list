
namespace A { 
  int A; 
  void f() { A = 0; } 
}

void f() { A = 0; } // expected-error {{unexpected namespace name 'A': expected expression}}
