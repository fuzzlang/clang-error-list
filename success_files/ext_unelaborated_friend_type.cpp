
namespace cwg68 {
  template<typename T> struct X {};
  
  struct ::cwg68::X<int> x1;
  struct ::cwg68::template X<int> x2;

  struct Y {
    friend struct X<int>;
    friend struct ::cwg68::X<char>;
    friend struct ::cwg68::template X<double>;
  };

  template<typename>
  struct Z {
    friend struct ::cwg68::template X<double>;
    friend typename ::cwg68::X<double>;
  };
  
  void f(int n);
  
  void g() {
    f(1, 2); // expected-error@-1 {{no matching function for call to 'f'}}
    //   expected-note@#cwg68-f-first {{candidate function not viable: requires single argument 'n', but 2 arguments were provided}}
  }
}
