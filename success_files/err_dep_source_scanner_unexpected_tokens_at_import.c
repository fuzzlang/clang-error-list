
void function() {
    @import x; a // expected-error {{unexpected extra tokens at end of @import declaration}}
}
