
namespace std {
  template<typename T> int &move(T);
}

int bad_signature = std::move(0); // expected-error {{unsupported signature for 'std::move<int>'}}
