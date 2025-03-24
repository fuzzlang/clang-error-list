
namespace cwg506 { // cwg506: yes
  struct NonPod { ~NonPod(); };
  void f(...);
  void g() {
    NonPod np;
    f(np); // expected-error@-1 {{cannot pass a non-POD argument to a variadic function}}
  }
}
