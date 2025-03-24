
struct IncompleteSt; // Incomplete type declaration

IncompleteSt e; // Declaration of threadprivate variable

#pragma omp threadprivate(e) // expected-error {{threadprivate variable with incomplete type 'IncompleteSt'}}

int main() {
  return 0;
}
