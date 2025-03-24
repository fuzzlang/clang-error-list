
extern int A();

void func() {
    for (extern int a : A()) {} // expected-error {{loop variable 'a' may not be declared 'extern'}}
}
