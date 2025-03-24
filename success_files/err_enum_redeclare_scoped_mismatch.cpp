
enum class Redeclare2; // expected-note{{previous declaration is here}}
enum Redeclare2; // expected-error{{previously declared as scoped}}
