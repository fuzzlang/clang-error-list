
void bar(int*);

class c {
  int var;
  static int svar;
  void foo() { 
    bar(&var); 
    bar(&svar);  
  }

  static void wibble() {
    bar(&var); // expected-error{{invalid use of member 'var' in static member function}}
    bar(&svar); 
  }
};

enum E {
  Enumerator
};

void test() {
  (void)&Enumerator; // expected-error{{cannot take the address of an rvalue of type 'E'}}
}

template<int N>
void test2() {
  (void)&N; // expected-error{{cannot take the address of an rvalue of type 'int'}}
}

void xpto();
void (*xyz)(void) = &xpto;

struct PR11066 {
  static int foo(short);
  static int foo(float);
  void test();
};

void PR11066::test() {
  int (PR11066::*ptr)(int) = & &PR11066::foo; // expected-error{{extra '&' taking address of overloaded function}}
}
