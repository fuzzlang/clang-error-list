
int main() {
  #pragma float_control(except, on)
  #pragma float_control(precise, off) // expected-error {{'#pragma float_control(precise, off)' is illegal when except is enabled}}
}
