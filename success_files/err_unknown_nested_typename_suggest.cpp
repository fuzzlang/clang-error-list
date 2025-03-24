
namespace std {
  template<typename T> class basic_string { 
  public:
    int find(const char *substr);
    static const int npos = -1; 
  };

  typedef basic_string<char> string; 
}

namespace otherstd { 
  using namespace std;
}

using namespace std;

other_std::strng str1; // expected-error{{use of undeclared identifier 'other_std'; did you mean 'otherstd'?}}
