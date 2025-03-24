
void foo() {
#pragma acc loop device_type(*) finalize
  for (int i = 0; i < 10; i++) {
    // loop body
  }
}
