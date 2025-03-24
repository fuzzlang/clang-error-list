
struct D {
  static void ~D(int, ...) const { } // expected-error{{destructor cannot be declared 'static'}} \
                                     // expected-error{{destructor cannot have any parameters}} \
                                     // expected-error{{destructor cannot be variadic}} \
                                     // expected-error{{'const' qualifier is not allowed on a destructor}}
};
