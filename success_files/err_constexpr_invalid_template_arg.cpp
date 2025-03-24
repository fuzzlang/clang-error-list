
namespace cwg100 { // cwg100: yes
  template<const char (*)[4]> struct A {}; // #cwg100-A
  template<const char (&)[4]> struct B {}; // #cwg100-B
  template<const char *> struct C {}; // #cwg100-C
  template<const char &> struct D {}; // #cwg100-D
  A<&"bar"> a; // #cwg100-a
}
