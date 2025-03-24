
class foo { };

class bar : boo { }; // expected-error{{unknown class name 'boo'; did you mean 'foo'?}}
