
class C {
public:
  int b : 1, w : 2;
  int : 1, : 2;
  typedef int E : 1; // expected-error {{typedef member 'E' cannot be a bit-field}}
};
