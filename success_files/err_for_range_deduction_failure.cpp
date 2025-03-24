
void f();
void f(int);

void example() {
    for (double a : f) { // expected-error {{cannot use type '<overloaded function type>' as a range}}
    }
}
