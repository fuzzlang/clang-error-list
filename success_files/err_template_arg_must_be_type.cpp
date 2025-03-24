
namespace Sample {
template <typename T> struct X {};
// expected-note@-1 {{template parameter is declared here}}

template <typename T>
void Run(const int& points) {
// expected-note@-1 {{'points' declared here}}
  auto outer_lambda = []() {
    auto inner_lambda = [](const X<Points>&) {}; // expected-error{{template argument must be a type}}
  };
}
}
