
class HasNonTrivialDestructor {
public:
  ~HasNonTrivialDestructor() {}
};

void ReturnsVoid();

void TestNonTrivialDestructorInScope() {
  HasNonTrivialDestructor foo; // expected-note {{jump exits scope of variable with non-trivial destructor}}
  [[clang::musttail]] return ReturnsVoid(); // expected-error {{cannot perform a tail call from this return statement}}
}
