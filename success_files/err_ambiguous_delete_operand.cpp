
class U {
  operator int*();
  operator void*(); // operator overload making delete ambiguous
};

void testDelete() {
  U u;
  delete u; // expected-error {{ambiguous conversion of delete expression of type 'U' to a pointer}}
}
