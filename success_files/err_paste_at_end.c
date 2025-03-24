
#define a   a ## ## // expected-error {{'##' cannot appear at end of macro expansion}}

int main() {
    return 0;
}
