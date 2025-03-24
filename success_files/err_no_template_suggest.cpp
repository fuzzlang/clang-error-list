
namespace std {
  template<typename T> class basic_string { // expected-note 3{{'basic_string' declared here}}
  public:
    int find(const char *substr); // expected-note{{'find' declared here}}
    static const int npos = -1; // expected-note{{'npos' declared here}}
  };

  typedef basic_string<char> string; // expected-note 2{{'string' declared here}}
}

bool test_string(std::string s) {
  basc_string<char> b1; // expected-error{{no template named 'basc_string'; did you mean 'basic_string'?}}
  return true;
}
