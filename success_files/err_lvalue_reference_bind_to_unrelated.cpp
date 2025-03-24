
namespace cwg162 { // cwg162: 19
  struct A {
    char &f(char);
    static int &f(int);

    void g() {
      int &a = (&A::f)(0); // expected-error {{binding reference of type 'char &' to an unrelated type 'int'}}
      char &b = (&A::f)('0'); // expected-error {{binding reference of type 'int &' to an unrelated type 'char'}}
    }
  };

  char &A::f(char) {
    static char c;
    return c;
  }

  int &A::f(int) {
    static int i;
    return i;
  }
}

