
class C {
public:
  mutable int &mir; // expected-error {{'mutable' cannot be applied to references}}
};
