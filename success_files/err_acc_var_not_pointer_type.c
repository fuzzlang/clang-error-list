
void foo() {
  int array[10];
  int value = 2;
  struct {
    int array[10];
    int value;
  } s = { {0}, 0 };

#pragma acc serial deviceptr(s.array[s.value], s.array[s.value:5]) self
  {
    // Some computation
  }
}
