
void (* restrict fp)(void); // expected-error {{pointer to function type 'void (void)' may not be 'restrict' qualified}}
