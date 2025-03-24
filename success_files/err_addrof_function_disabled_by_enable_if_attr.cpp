
int noOvlNoCandidate(int x) __attribute__((enable_if(0, "condition failed")));

int main() {
    int (*p)(int) = noOvlNoCandidate; // expected-error{{cannot take address of function 'noOvlNoCandidate' because it has one or more non-tautological enable_if conditions}}
}
