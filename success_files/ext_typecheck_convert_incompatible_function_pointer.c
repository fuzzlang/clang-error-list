
typedef int (*MyFnTyA)(int *, char *);

int bar(char *a, int *b) { return 0; }
int foo(MyFnTyA x) { return 0; } // expected-note {{passing argument to parameter 'x' here}}

void baz(void) {
  foo(&bar); // expected-error {{incompatible function pointer types passing 'int (*)(char *, int *)' to parameter of type 'MyFnTyA' (aka 'int (*)(int *, char *)')}}
}
