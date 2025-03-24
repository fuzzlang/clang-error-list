
struct DeletingPlaceholder {
  int* f() { 
    delete f; // expected-error {{reference to non-static member function must be called; did you mean to call it with no arguments?}}
    return 0; 
  }

  int* g(int, int) { 
    delete g; // expected-error {{reference to non-static member function must be called}} 
    return 0; 
  } 
};
