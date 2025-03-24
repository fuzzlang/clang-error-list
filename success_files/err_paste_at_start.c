
#define e   ## ## e // expected-error {{'##' cannot appear at start of macro expansion}}

int main() {
    return 0;
}
