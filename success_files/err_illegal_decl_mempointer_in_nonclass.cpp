
struct A {};
enum B { Dummy };
namespace C {}

int B::*pbi; // expected-error {{'pbi' does not point into a class}}
