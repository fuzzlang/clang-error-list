
enum Redeclare3 : int; // expected-note{{previous declaration is here}}
enum Redeclare3; // expected-error{{previously declared with fixed underlying type}}
