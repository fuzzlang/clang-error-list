
namespace cwg1762 { // cwg1762: 14
#if __cplusplus >= 201103L
  float operator ""_E(const char *);
  float operator ""E(const char *); // expected-error@-1 {{invalid suffix on literal; C++11 requires a space between literal and identifier}}
#endif
}
