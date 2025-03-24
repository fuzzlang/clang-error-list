
namespace cwg626 { // cwg626: yes
#define STR(x) #x
  char c[2] = STR(c); // ok, type matches
  wchar_t w[2] = STR(w); // expected-error{{initialization of array 'w' of type 'wchar_t' with an initializer of type 'const char [4]'}}
}
