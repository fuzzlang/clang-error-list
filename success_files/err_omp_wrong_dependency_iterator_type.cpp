
class GoodIter1 {
public:
  GoodIter1& operator++() { return *this; }
  GoodIter1 operator++(int) { return *this; }
  bool operator<(const GoodIter1& other) const { return true; }
  long operator-(const GoodIter1& other) const { return 0; }
};

int main() {
  GoodIter1 I1, E1;
  #pragma omp for collapse(3) // expected-error@+1 {{expected an integer or a pointer type of the outer loop counter 'I' for non-rectangular nests}}
  for (GoodIter1 I = I1; I < E1; I++) // expected-note 2 {{'I' declared here}}
    for (int i = (I - I1) * 10 + 25; i < 23; i += 1)
      for (int j = 0; j < 10; j++) {}
}
