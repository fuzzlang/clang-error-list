
bool r2 = requires { requires true; };

bool r3 = requires (int a, ...) { requires true; };

// expected-error@-1 {{a requires expression must contain at least one requirement}}
