
static int i2 = 5; // expected-note 1 {{previous definition is here}}
int i2 = 3; // expected-error{{non-static declaration of 'i2' follows static declaration}}
