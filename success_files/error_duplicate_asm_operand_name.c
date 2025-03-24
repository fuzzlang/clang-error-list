
void example() {
  // expected-error@+2 {{duplicate use of asm operand name "lab"}}
  // expected-note@+1 {{asm operand name "lab" first referenced here}}
  asm goto ("" : : : : lab, lab, lab2, lab);
}
