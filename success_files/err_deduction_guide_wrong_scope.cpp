
namespace PR49735 {
template<class> struct B; // expected-note 2{{template is declared here}}

struct A1 {
  B() noexcept(false); // expected-error {{deduction guide must be declared in the same scope as template 'PR49735::B'}}
};

struct A2 {
  template <typename Ty>
  B() noexcept(false); // expected-error {{deduction guide must be declared in the same scope as template 'PR49735::B'}}
};
}
