
namespace std {
  template<typename T> class basic_string { 
  public:
    int find(const char *substr); 
    static const int npos = -1; 
  };

  typedef basic_string<char> string; 
}

bool test_string(std::string s) {
  std::basic_sting<char> b2; // expected-error{{no template named 'basic_sting' in namespace 'std'; did you mean 'basic_string'?}}
  return s.find("hello") == std::string::npos; 
}
