
struct SC {
  int C;
};

int main() {
  SC r;

  #pragma omp target map(r.C, r.C)    // lt50-error {{variable already marked as mapped in current construct}} lt50-note {{used here}}
  {}
}
