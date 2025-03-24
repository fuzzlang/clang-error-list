
struct omp_interop_t {
  int a;
  int b;
};

void test() {
  omp_interop_t *ptr = nullptr;
  
  #pragma omp interop init(target:ptr->a + ptr->b) init(target:Another)
}
