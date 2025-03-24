
// expected-error@-1 {{cannot jump from this goto statement to its label}}
//   expected-note@#cwg467-k {{jump bypasses variable initialization}}
int stuff() {
    return 42; // Example initialization for `k`
}

int main() {
    int k = stuff(); // #cwg467-k
  later:
    return k;
}

namespace cwg468 { // cwg468: yes c++11
  template<typename> struct A {
    template<typename> struct B {
      static int C;
    };
  };
  int k = cwg468::template A<int>::template B<char>::C;
}
