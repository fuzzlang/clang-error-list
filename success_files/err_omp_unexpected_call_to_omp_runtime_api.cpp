
extern int omp_get_num_threads(void);

int main(int argc, char **argv) {
  int A = 0;
#pragma omp parallel for order(concurrent)
  for (int i = 0; i < 10; ++i) {
    omp_get_num_threads(); // omp51-error {{calls to OpenMP runtime API are not allowed within a region that corresponds to a construct with an order clause that specifies concurrent}}
  }
}
