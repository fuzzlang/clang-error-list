
int main(int argc, char **argv) {
  #pragma omp depobj() allocate(argc) // expected-error {{expected expression}} expected-error {{expected depobj expression}} expected-error {{unexpected OpenMP clause 'allocate' in directive '#pragma omp depobj'}}
  {
  }
  return 0;
}
