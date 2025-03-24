
void b3 (void) { 
    for (static int f;;); // expected-error {{declaration of non-local variable}} 
}
