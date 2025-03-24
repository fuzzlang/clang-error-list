
struct D2 {
  const ~D2() { } // expected-error{{'const' qualifier is not allowed on a destructor}}
};
