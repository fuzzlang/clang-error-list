
typedef struct {
  int a;
  int b;
} A;

void t3(void) {
  __asm { mov eax, [eax] UndeclaredId } // expected-error {{unknown token in expression}} expected-error {{use of undeclared label 'UndeclaredId'}}
  
  // expected-error@+2 {{unexpected type name 'A': expected expression}}
  // expected-error@+1 {{unknown token in expression}}
  __asm { mov eax, [eax] A }
}
