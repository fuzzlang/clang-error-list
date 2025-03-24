
struct A {};

int& A::*pdr; // expected-error {{'pdr' declared as a member pointer to a reference}}
