
namespace cwg2553 { // cwg2553: 18 review 2023-07-14
struct B {
  virtual void f(this B&); // expected-error {{explicit object parameter cannot be declared outside of a non-static member function; did you mean to include it in a member function?}}
};
}
