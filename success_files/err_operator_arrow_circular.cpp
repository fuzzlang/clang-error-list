
struct AX { 
  AX& operator ->(); // expected-note {{declared here}} 
  int b; 
}; 

void m() { 
  AX a; 
  a->b = 0; // expected-error {{circular pointer delegation detected}} 
}
