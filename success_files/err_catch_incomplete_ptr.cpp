
struct P;

int main() {
    try {}
    catch (struct P *) {} // expected-error@-1 {{cannot catch pointer to incomplete type 'struct P'}}
    catch (struct P {} *) {} // expected-error@-1 {{'P' cannot be defined in a type specifier}}
}
