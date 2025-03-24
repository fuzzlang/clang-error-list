
int NotAProtoType(); // expected-note{{add 'void' to the parameter list to turn an old-style K&R function declaration into a prototype}}

int TestCalleeNotProtoType(void) {
  __attribute__((musttail)) return NotAProtoType(); // expected-error{{'musttail' attribute requires that both caller and callee functions have a prototype}}
}
