
class E1 {
public:
  const int a; // expected-note{{declared here}}
  E1() : a(0) {}
};

E1 e1, e2;

void j() {
  e1 = e2; // expected-error@-2 {{object of type 'E1' cannot be assigned because its copy assignment operator is implicitly deleted}}
}
