
int foo1(int case, int throw, int y) { // expected-error {{invalid parameter name: 'case' is a keyword}}
    return case + throw + y;
}
