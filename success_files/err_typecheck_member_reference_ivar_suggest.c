
@interface B {
    int her_ivar; // expected-note{{'her_ivar' declared here}}
}

@end

@implementation B

- (void)inst_method1:(int)a {
    self->herivar = a; // expected-error{{'B' does not have a member named 'herivar'; did you mean 'her_ivar'?}}
}

@end
