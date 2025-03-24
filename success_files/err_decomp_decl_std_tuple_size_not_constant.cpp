
namespace std {
  template<typename T> struct tuple_size;
}

struct Bad2 {};

template<> struct std::tuple_size<Bad2> {
  const int value = 5;
};

void no_tuple_size_4() {
  auto [x, y] = Bad2(); // expected-error {{cannot decompose this type; 'std::tuple_size<Bad2>::value' is not a valid integral constant expression}}
}
