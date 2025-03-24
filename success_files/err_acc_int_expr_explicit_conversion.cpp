
struct NotConvertible {};

struct ExplicitConvertOnly {
  explicit operator int() const; // #EXPL_CONV
} Explicit;

void Test() {
  #pragma acc parallel num_gangs(Explicit, NotConvertible())
  while(1);
}
