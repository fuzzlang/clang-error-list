
namespace ns {
    template <class T> using foo = T; // This is a valid using declaration
}

template <class T> using ns::foo; // expected-error {{cannot template a using declaration}}
